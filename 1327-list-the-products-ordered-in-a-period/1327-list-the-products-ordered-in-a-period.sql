# Write your MySQL query statement below
select t2.product_name  , sum(t1.unit) as unit
from Orders t1
LEFT JOIN Products t2
ON t2.product_id = t1.product_id
where t1.order_date>='2020-02-01' and t1.order_date<='2020-02-29' 
GROUP BY t1.product_id
having unit>=100 ;