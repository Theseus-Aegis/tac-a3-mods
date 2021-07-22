use arma_rs::{rv, rv_handler};

const REST_ENDPOINT: &str = "https://theseus-aegis.com:8443/apollo";

macro_rules! url {
    ($($args:expr),*) => {{
        let mut requrl: String = String::from(REST_ENDPOINT);
        $(
            requrl = format!("{}/{}", requrl, $args);
        )*
        requrl
    }}
}

fn request(api: String) -> String {
    println!("Request: {}", api);
    let response = reqwest::blocking::get(&api).unwrap().text().unwrap();
    println!("Response: {}", response);
    response
}

#[rv]
pub fn load_armory(category: String, player_id: String, debug: bool) -> String {
    request(url!("armory", category, player_id, debug))
}

#[rv]
pub fn load_player(player_id: String, debug: bool) -> String {
    request(url!("loadInfantry", player_id, debug))
}

#[rv]
pub fn get_accessible_item_classes(player_id: String) -> String {
    request(url!("getAccessibleItemClasses", player_id))
}

#[rv]
pub fn get_training_identifiers(player_id: String) -> String {
    request(url!("getTrainingIdentifiers", player_id))
}

#[rv]
pub fn version() -> &'static str {
    env!("CARGO_PKG_VERSION")
}

#[rv_handler]
fn init() {}
