/*
Name: Count of positives / sum of negatives
Kata: 8 kyu
Link: https://www.codewars.com/kata/576bb71bbbcf0951d5000044

Description: Given an array of integers.
Return an array, where the first element is the count of positives numbers and the second element is
sum of negative numbers. 0 is neither positive nor negative.
If the input is an empty array or is null, return an empty array.
Example
For input [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, -11, -12, -13, -14, -15], you should return [10, -65].
*/

fn count_positives_sum_negatives(input: Vec<i32>) -> Vec<i32> {
    let mut ret = vec![0, 0];
    if input.is_empty() {
        return input;
    }
    for num in input {
        if num > 0 {
            ret[0] += 1;
        }
        else if num < 0 {
            ret[1] += num;
        }
    }
    return ret;
}
