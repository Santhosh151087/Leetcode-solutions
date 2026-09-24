# Write your MySQL query statement below
select t1.customer_id from
Customer t1
group by customer_id
having count(DISTINCT product_key) = (select count(*) from Product);