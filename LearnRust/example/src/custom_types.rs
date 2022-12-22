// mod custom_types 
use std::fmt;

#[derive(Debug)]
struct Person {
    name: String,
    age: u8,
}

// A unit struct
struct Unit;

// A tuple struct
struct Pair(i32, f32);

// A struct with two fields
#[derive(Debug)]
pub struct Point {
    x: f32,
    y: f32,
}

// Structs can be reused as fields of another struct
pub struct Rectangle {
    // A rectangle can be specified by where the top left and bottom right
    // corners are in space.
    top_left: Point,
    bottom_right: Point,
}

impl Point {
  pub fn from(x : f32, y : f32) -> Point {
    Point{ x, y }
  }
}

enum WebEvent {
    // An `enum` may either be `unit-like`,
    PageLoad,
    PageUnload,
    // like tuple structs,
    KeyPress(char),
    Paste(String),
    // or c-like structures.
    Click { x: i64, y: i64 },
}

enum Operation {
    Add,
    Subtract,
}

impl Operation {
    fn run(&self, x: i32, y: i32) -> i32 {
        match self {
            Self::Add => x + y,
            Self::Subtract => x - y,
        }
    }
}

enum Status {
    Rich,
    Poor,
}

enum Work {
    Civilian,
    Soldier,
}


impl fmt::Display for Point {
  fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
      write!(f, "x:{}, y:{}", self.x, self.y)
  }
}

impl Rectangle {
  pub fn from(tx:f32, ty:f32, bx:f32, by:f32) -> Rectangle {
      Rectangle{ 
        top_left: Point{x: tx, y: ty},
        bottom_right: Point{x: bx, y: by},
      }
  }

  pub fn area(&self) -> f32 {
    let w = self.bottom_right.x - self.top_left.x;
    let h = self.bottom_right.y - self.top_left.y;
    w * h
  }

  pub fn sqaure(p : Point, w : f32) -> Rectangle {
    // Self가 현재 impl 블록의 타잎이고, self는 그 값이다.
    Self::from(p.x, p.y, p.x + w, p.y + w)
  }
}

// A function which takes a `WebEvent` enum as an argument and
// returns nothing.
fn inspect(event: WebEvent) {
    match event {
      WebEvent::PageLoad => println!("PageLoad"),
      WebEvent::PageUnload => println!("PageUnload"),
      WebEvent::KeyPress(c) => println!("KeyPress({})", c),
      WebEvent::Paste(s) => println!("Paste({})", s),
      WebEvent::Click{x, y} => println!("Click(x: {}, y: {})", x, y),
    }
}

pub fn look_custom_types() {
    // Create struct with field init shorthand
    let name = String::from("Peter");
    let age = 27;

    // name: name, age: age와 같다. 
    let peter = Person { name, age };

    // Print debug struct
    println!("{:?}", peter);

    // Instantiate a `Point`
    let point: Point = Point { x: 10.3, y: 0.4 };

    // Access the fields of the point
    println!("point coordinates: ({}, {})", point.x, point.y);

    // Make a new point by using struct update syntax to use the fields of our
    // other one
    let bottom_right = Point { x: 5.2, ..point };

    // `bottom_right.y` will be the same as `point.y` because we used that field
    // from `point`
    println!("second point: ({}, {})", bottom_right.x, bottom_right.y);

    // Destructure the point using a `let` binding
    let Point { x: left_edge, y: top_edge } = point;

    let _rectangle = Rectangle {
        // struct instantiation is an expression too
        top_left: Point { x: left_edge, y: top_edge },
        bottom_right: bottom_right,
    };

    // Instantiate a unit struct
    let _unit = Unit;

    // Instantiate a tuple struct
    let pair = Pair(1, 0.1);

    // Access the fields of a tuple struct
    println!("pair contains {:?} and {:?}", pair.0, pair.1);

    // Destructure a tuple struct
    let Pair(integer, decimal) = pair;

    println!("pair contains {:?} and {:?}", integer, decimal);
}

pub fn look_enum_inspect() {
    let pressed = WebEvent::KeyPress('x');
    // `to_owned()` creates an owned `String` from a string slice.
    let pasted  = WebEvent::Paste("my text".to_owned());
    let click   = WebEvent::Click { x: 20, y: 80 };
    let load    = WebEvent::PageLoad;
    let unload  = WebEvent::PageUnload;

    inspect(pressed);
    inspect(pasted);
    inspect(click);
    inspect(load);
    inspect(unload);
}

pub fn look_enum_op() {
  let op = Operation::Add;

  let result = Operation::run(&op, 3, 5);
  println!("x + y = {}", result);
}

pub fn look_enum_scopes() {
    // Explicitly `use` each name so they are available without
    // manual scoping.
    use crate::custom_types::Status::{Poor, Rich};
    // Automatically `use` each name inside `Work`.
    use crate::custom_types::Work::*;

    // Equivalent to `Status::Poor`.
    let status = Poor;
    // Equivalent to `Work::Civilian`.
    let work = Civilian;

    match status {
        // Note the lack of scoping because of the explicit `use` above.
        Rich => println!("The rich have lots of money!"),
        Poor => println!("The poor have no money..."),
    }

    match work {
        // Note again the lack of scoping.
        Civilian => println!("Civilians work!"),
        Soldier  => println!("Soldiers fight!"),
    }
}