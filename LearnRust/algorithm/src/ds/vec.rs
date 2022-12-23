

#[cfg(test)]
mod test {

  #[test]
  fn test_basic_usage() {
    let mut xs: Vec<i32> = vec![];
    xs.push(3);

    assert!(xs.len() == 1);
  }

}
