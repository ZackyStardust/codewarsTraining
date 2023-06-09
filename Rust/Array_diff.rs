/*
Name: Array.diff
Kata: 6 kyu
Link: https://www.codewars.com/kata/523f5d21c841566fde000009/rust

Description: Your goal in this kata is to implement a difference function,
which subtracts one list from another and returns the result.

It should remove all values from list a, which are present in list b keeping their order.

array_diff(vec![1,2], vec![1]) == vec![2]
If a value is present in b, all of its occurrences must be removed from the other:

array_diff(vec![1,2,2,2,3], vec![2]) == vec![1,3]
*/

fn array_diff<T: PartialEq>(a: Vec<T>, b: Vec<T>) -> Vec<T> {
    let mut ret: Vec<T> = vec![];
    if a.is_empty() {
        return a;
    }
    for num in a {
        ret.push(num);
    }
    for num in b {
        ret.retain(|x| x != &num);
    }
    return ret;
}
  
