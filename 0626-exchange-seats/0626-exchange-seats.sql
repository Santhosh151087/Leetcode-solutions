# Write your MySQL query statement below
SELECT CASE 
WHEN id%2=0  THEN id-1 
WHEN id%2=1 and id+1 in (select id from Seat) THEN id+1
ELSE id END  
as id , student 
from Seat 
order by id;