# Write your MySQL query statement below
select t1.product_id  ,t1.new_price  as price
from Products t1
where t1.change_date = (select max(change_date) from Products  where change_date <='2019-08-16' && product_id = t1.product_id)
group by t1.product_id

union 
select product_id , 10 as price 
from Products 
group by product_id
having min(change_date) >'2019-08-16';

