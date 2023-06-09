/*
Name: L1: Set Alarm
Kata: 8 kyu
Link: https://www.codewars.com/kata/568dcc3c7f12767a62000038

Description: Write a function named set_alarm which receives two parameters. The first parameter,
employed, is true whenever you are employed and the second parameter, vacation is true whenever you
are on vacation.

The function should return true if you are employed and not on vacation
(because these are the circumstances under which you need to set an alarm).
It should return false otherwise. Examples:

set_alarm(true, true) -> false
set_alarm(false, true) -> false
set_alarm(false, false) -> false
set_alarm(true, false) -> true
*/

fn set_alarm(employed: bool, vacation: bool) -> bool {
    if employed == true && vacation == false {
        return true;
    }
    return false;
}
