// mod vec 
// - implementation following rustonomicon tutorial 

// 점진적으로 개선해 나가는 방식이므로 코드가 지워질 수 있다. 
// 이전 구조는 mod 안으로 넣어서 보관한다. 

// Layout 

mod step2 {
  use std::ptr::NonNull;
  use std::marker::PhantomData;
  use std::alloc::{self, Layout};


  pub struct Vec<T> {
    ptr : NonNull<T>,
    cap : usize, 
    len : usize, 
    _marker : PhantomData<T>
  }

  unsafe impl<T: Send> Send for Vec<T> {}
  unsafe impl<T: Sync> Sync for Vec<T> {}

  use std::mem;

  impl<T> Vec<T> {
      pub fn new() -> Self {
          assert!(mem::size_of::<T>() != 0, "We're not ready to handle ZSTs");
          Vec {
              ptr: NonNull::dangling(),
              len: 0,
              cap: 0,
              _marker: PhantomData,
          }
      }

      fn grow(&mut self) {
        // layout을 먼저 정하고 필요한 메모리를 만든 후에 NonNull로 
        // 타잎의 데이터를 만든다.  
        let (new_cap, new_layout) = if self.cap == 0 {
            (1, Layout::array::<T>(1).unwrap())
        } else {
            // This can't overflow since self.cap <= isize::MAX.
            let new_cap = 2 * self.cap;

            // `Layout::array` checks that the number of bytes is <= usize::MAX,
            // but this is redundant since old_layout.size() <= isize::MAX,
            // so the `unwrap` should never fail.
            let new_layout = Layout::array::<T>(new_cap).unwrap();
            (new_cap, new_layout)
        };

        // Ensure that the new allocation doesn't exceed `isize::MAX` bytes.
        assert!(new_layout.size() <= isize::MAX as usize, "Allocation too large");

        let new_ptr = if self.cap == 0 {
            unsafe { alloc::alloc(new_layout) }
        } else {
            let old_layout = Layout::array::<T>(self.cap).unwrap();
            let old_ptr = self.ptr.as_ptr() as *mut u8;
            // realloc으로 이전의 데이터를 옮긴다.  
            unsafe { alloc::realloc(old_ptr, old_layout, new_layout.size()) }
        };

        // If allocation fails, `new_ptr` will be null, in which case we abort.
        self.ptr = match NonNull::new(new_ptr as *mut T) {
            Some(p) => p,
            None => alloc::handle_alloc_error(new_layout),
        };
        self.cap = new_cap;
    }

    pub fn push(&mut self, elem: T) {
      if self.len == self.cap { self.grow(); }

      unsafe {
          std::ptr::write(self.ptr.as_ptr().add(self.len), elem);
      }

      // Can't fail, we'll OOM first.
      self.len += 1;
    }

    pub fn pop(&mut self) -> Option<T> {
      if self.len == 0 {
          None
      } else {
          self.len -= 1;
          unsafe {
              Some(std::ptr::read(self.ptr.as_ptr().add(self.len)))
          }
      }
    }

    pub const fn len(&self) -> usize {
      self.len
    }
}

impl<T> Drop for Vec<T> {
    fn drop(&mut self) {
        if self.cap != 0 {
            while let Some(_) = self.pop() { }
            let layout = Layout::array::<T>(self.cap).unwrap();
            unsafe {
                alloc::dealloc(self.ptr.as_ptr() as *mut u8, layout);
            }
        }
    }
}
 
#[cfg(test)]
mod test{
  use super::*;

  #[test]
  fn test_new() {
    let vs = Vec::<i32>::new();
    assert!(vs.cap == 0);
    assert!(vs.len == 0);
  }

  #[test]
  fn test_push_pop() {
    let mut vs = Vec::<i32>::new();
    vs.push(0);
    vs.push(1);

    while let Some(v) = vs.pop() {
      println!("pop:{}", v);
    }
  }

  #[test]
  fn test_layout() {
    let mut d = 0_i32;

    // Vec를 어떻게 만들지? 
    let vs = super::Vec::<i32> { 
      ptr: NonNull::new(&mut d).unwrap(), 
      cap: 0, 
      len: 0, 
      _marker: PhantomData
    };
  }
  
  fn test_nonnull() {
    let vs = Vec::<i32>::new();

    println!("cap: {}", vs.cap);
  }
}
   
}

mod step1 {

pub struct Vec<T> {
    ptr: *mut T, // how to allocate *mut T (a mutable pointer with the layout of T)
    cap: usize,
    len: usize,
}

#[cfg(test)]
mod test{

  #[test]
  fn test_layout() {
    let mut d = 0_i32;

    // Vec를 어떻게 만들지? 
    let vs = super::Vec::<i32> { 
      ptr: &mut d, 
      cap: 0, 
      len: 0 
    };

    println!("step1: {}", unsafe{ *(vs.ptr) })
  }
  // 참조는 거의 포인터이다. mutable 참조와 참조가 있고, 
  // mutable 참조는 alias 제한이 있다.
}

}


#[cfg(test)]
mod test {

  #[test]
  fn test_basic_usage() {
    let mut xs: Vec<i32> = vec![];
    xs.push(3);

    assert!(xs.len() == 1);
  }

}

