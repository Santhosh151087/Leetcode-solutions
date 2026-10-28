# Write your MySQL query statement below
SELECT t1.id , 
CASE  
WHEN t1.p_id is null THEN 'Root'
WHEN ( select count(id) from Tree where p_id = t1.id ) =0 THEN 'Leaf' 
ELSE 'Inner'
END AS type
from Tree t1;
