enum List {
    Cons(i32, Box<List>), 
    Nil
}

// use crate means this crate.
use crate::List::{Cons, Nil};

fn test_list() {
    let _lst : List = Cons(3, Box::new(Cons(5, Box::new(Nil))));
}

struct MyBox<T>(T);

impl<T> MyBox<T> {
    fn new(x: T) -> MyBox<T> {
        MyBox(x)
    }
}

use std::ops::Deref;

impl<T> Deref for MyBox<T> {
    type Target = T;

    fn deref(&self) -> &Self::Target {
        &self.0
    }
}

fn test_deref() {
    let x = 5;
    let y : MyBox<i32> = MyBox::new(x);

    assert_eq!(x, *y);
}

fn main() {
   test_list(); 
   test_deref();
}
