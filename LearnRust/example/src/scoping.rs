// mod scoping 

// Box의 Drop 구현은 컴파일러가 한다.(현재 stable 구현)

struct TraceBox<T> {
  value : Box<T>
}

// TraceBox<T>의 적절한 Drop 구현은 무엇인가? 
// Drop 구현이 없어도 value는 잘 해제되어야 한다. 

impl<T> TraceBox<T> {
  fn new(v : T) -> TraceBox<T> {
    TraceBox::<T> {
      value: Box::new(v)
    }
  }
}

// raii.rs
fn create_box() {
    // Allocate an integer on the heap
    let _box1 = Box::new(3_i32);

    // `_box1` is destroyed here, and memory gets freed
}

pub fn look_raii() {
    // Allocate an integer on the heap
    let _box2 = Box::new(5_i32);

    // A nested scope:
    {
        // Allocate an integer on the heap
        let _box3 = Box::new(4_i32);

        // `_box3` is destroyed here, and memory gets freed
    }

    // Creating lots of boxes just for fun
    // There's no need to manually free memory!
    for _ in 0_u32..1_000 {
        create_box();

        let _tbox = TraceBox::<i32>::new(10);
    }

    // `_box2` is destroyed here, and memory gets freed
}

// This function takes ownership of the heap allocated memory
fn destroy_box(c: Box<i32>) {
    println!("Destroying a box that contains {}", c);

    // `c` is destroyed and the memory freed
}

pub fn look_ownership_move() {
    // _Stack_ allocated integer
    let x = 5u32;

    // *Copy* `x` into `y` - no resources are moved
    let y = x;

    // Both values can be independently used
    println!("x is {}, and y is {}", x, y);

    // `a` is a pointer to a _heap_ allocated integer
    let a = Box::new(5_i32);

    println!("a contains: {}", a);

    // *Move* `a` into `b`
    let b = a;
    // The pointer address of `a` is copied (not the data) into `b`.
    // Both are now pointers to the same heap allocated data, but
    // `b` now owns it.
    
    // Error! `a` can no longer access the data, because it no longer owns the
    // heap memory
    //println!("a contains: {}", a);
    // TODO ^ Try uncommenting this line

    // This function takes ownership of the heap allocated memory from `b`
    destroy_box(b);

    // Since the heap memory has been freed at this point, this action would
    // result in dereferencing freed memory, but it's forbidden by the compiler
    // Error! Same reason as the previous Error
    // println!("b contains: {}", b);
    // TODO ^ Try uncommenting this line
}
