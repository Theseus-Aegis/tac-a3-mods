mod lib;

use crate::lib::*;

fn main() {
    println!("Version: {}", version());
    //get_accessible_item_classes(String::from("76561198048995566"));
    get_training_identifiers(String::from("76561198048995566"));
    //load_armory(String::from("rifle"), String::from("76561198048995566"), true);
}
