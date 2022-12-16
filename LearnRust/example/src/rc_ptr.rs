// mod rc_ptr aka. reference counted pointer 

use std::ops::Deref;
use std::boxed::Box;
use std::cell::RefCell;

struct Rc<T> {
  count: *mut i32,
  value: *mut T
}

impl<T> Rc<T> {
  fn new(t: T) -> Rc<T> {
    Rc {
      count: Box::into_raw(Box::new(1)),
      value: Box::into_raw(Box::new(t))
    }
  }
}

impl<T> Clone for Rc<T> {
  fn clone(&self) -> Rc<T> {
    unsafe {
      *self.count += 1;
    }

    Rc { count: self.count, value: self.value }
  }
}

impl<T> Drop for Rc<T> {
  fn drop(&mut self) {
    unsafe {
      *self.count -= 1;
      if *self.count == 0 {
        drop(Box::from_raw(self.value));
        drop(Box::from_raw(self.count));
      }
    }
  }
}

impl<T> Deref for Rc<T> {
  type Target = T;

  fn deref(&self) -> &T {
    unsafe { &*self.value }
  }
}

pub fn look_rc_ptr() {

  let rc1 = Rc::new(String::from("Hello Rc Ptr"));
  let rc2 = rc1.clone();

  // Rc가 DerefMut를 구현한다면 아래가 가능하다. 
  // let xptr: &mut i32 = &mut rc1;
  // let yptr: &mut i32 = &mut rc2;
  // 그래서, 두 곳에서 변경이 가능해진다.
  // *x = 2;
  // *y = 3;

  println!("rc2: {}", *rc2);
}

pub fn look_rc_cell_ptr() {

  let rc1 = Rc::new(RefCell::new(String::from("Hello Rc Ptr")));
  let rc2 = rc1.clone();

  println!("{}", *rc2.borrow());

  let mut s1 = rc1.borrow_mut(); // s1이 mut가 아닐 경우 아래 라인에서 mutable로 빌릴 수 없다.
  *s1 = String::from("Welcome");

  // println!("{}", *rc1.borrow());  // s1 borrow로 인해 패닉
}