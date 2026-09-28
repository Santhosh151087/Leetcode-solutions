# Write your MySQL query statement below
SELECT DISTINCT first.num as ConsecutiveNums from 
Logs first 
left join Logs second
on first.num = second.num
left join Logs third
on second.num = third.num
where first.id = second.id - 1 and second.id = third.id -1 
-- first.num = second.num and second.num = third.num; 
