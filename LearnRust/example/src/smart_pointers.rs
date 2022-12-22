// mod smart_pointers 
// https://stanford-cs242.github.io/f19/lectures/07-2-smart-pointers.html
// 위 문서를 읽고 다른 자료도 추가하여 포인터 사용을 이해한다. 


use std::alloc::{alloc, dealloc, Layout};
use std::{ptr, mem};
use std::ops::Deref;

// 초간단 Box<T> 구현을 보여준다. 
struct Box<T> {
  ptr: *mut T
}

impl<T> Box<T> {
  fn new(t: T) -> Box<T> {
    let ptr = unsafe {
      let layout = Layout::for_value(&t);   // from_value는 for_value로 바뀌었다. 
      let ptr = alloc(layout) as *mut T;    // ptr이 *mut T이지만 ptr 자체는 mutable일 필요가 없다. 
      ptr::copy(&t as *const T, ptr, layout.size());
      ptr
    };
    mem::forget(t); // 메모리 복사를 ptr로 했는데 굳이 forget을 해야 할까?
    Box { ptr }
  }
}

impl<T> Deref for Box<T> {
  type Target = T; // ?Sized로 정의된 트레이트의 Target을 지정

  fn deref(&self) -> &T {
    unsafe { &*self.ptr }
  }
}

impl<T> Drop for Box<T> {
  fn drop(&mut self) {
    unsafe {
      let layout = Layout::for_value(&*self.ptr);   // 메모리를 가져오는 것에 해당
      mem::drop(ptr::read(self.ptr));                   // destructor 호출에 해당한다.
      dealloc(self.ptr as *mut u8, layout);                 // free에 해당
    }
  }
}

pub fn look_raw_pointers() {
  let x : i32 = 3;
  let mut y : i32 = 3;

  let rx :&i32 = &x;
  let rx_raw_ptr = rx as *const i32;

  let ry  = &mut y; // mutable 참조 
  let ry_raw_ptr = ry as *mut i32;

  println!("i32 raw ptr. rx: {}", unsafe{ *rx_raw_ptr });
  println!("address of rx:{:p}", rx_raw_ptr);

  // c/c++처럼 안전하지 않게 접근할 수 있다. 
  unsafe { *ry_raw_ptr = 10 };

  println!("i32 raw ptr. ry: {}", unsafe{ *ry_raw_ptr });
  println!("address of ry: {:p}", ry_raw_ptr);
}

pub fn look_box() {

  let x: i32 = 1;
  let xbox: Box<i32> = Box::new(x);
  let xptr: &i32 = xbox.deref();

  println!("xptr: {}", *xptr);

  println!(
    "{}, {}", 
    *xbox,            // deref coercion(강제)로 인해 *xbox는 &T까지 돌려준다.
    *(xbox.deref())   // 따라서, 위는 옆과 같다.
  ); 

  // drop 구현이 되면 메모리 누수가 이제 없다. 
  // new, deref, drop 구현으로 unique_ptr과 같은 타잎을 만들었다. 
}

pub fn look_box_move() {

  let xv = Box::new(32);

  println!("xv: {}", *xv);

  let xv_moved = xv;

  println!("xv: {}", *xv_moved);

  // 아래는 컴파일 시 borrow checker가 체크한다. 
  // println!("xv: {}", *xv);
}