mod debug_1_2_1;

fn main() {
    ex_hello_world();
    ex_formatted_print();
    debug_1_2_1::ex_debug_print();
    debug_1_2_1::ex_debug_struct();
    debug_1_2_1::ex_custom_display();
    debug_1_2_1::ex_print_point();
}

// rust compiles in crates like C#
fn ex_hello_world() {
    println!("Hello world!");
}

fn ex_formatted_print() {

    // named argument
    println!("{subject}", subject="hello");

    // number formats
    println!("{:b}", 69420);
    println!("{:o}", 69420);
    println!("{:x}", 69420);
    println!("{:X}", 69420);

    // alignment and padding
    println!("{number:>5}", number=1);
    println!("{number:0<5}", number=1);

    // capture directly from env
    let number = 3;
    let width = 5;

    println!("{number:>width$}"); // $ sign required
}
    