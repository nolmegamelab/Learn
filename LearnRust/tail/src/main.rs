mod fileio;

fn main() {
    let result = fileio::read_file(path);

    match result {
        Some(s) => println!("{}", s),
        None => ()
    }
}

