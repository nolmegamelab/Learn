// mod expressions 

pub fn look_basic_expressions() {
    let x = 5_u32;

    let y = {
        let x_squared = x * x;
        let x_cube = x_squared * x;

        // This expression will be assigned to `y`
        x_cube + x_squared + x
    };

    let z = {
        // The semicolon suppresses this expression and `()` is assigned to `z`
        // expression을 먼저 처리하고 () 제어문으로 한다.  
        let _ = 2 * x;
    };

    println!("x is {}", x);
    println!("y is {}", y);
    println!("z is {:?}", z); // unit은 기본 fmt::Display 구현이 없다. 
}