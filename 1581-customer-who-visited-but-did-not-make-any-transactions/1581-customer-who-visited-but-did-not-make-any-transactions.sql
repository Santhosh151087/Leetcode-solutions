# Write your MySQL query statement below
select DISTINCT customer_id , COUNT(*) AS count_no_trans from Visits
LEFT JOIN Transactions
ON Visits.visit_id = Transactions.visit_id
where Transactions.visit_id is null 
GROUP BY customer_id;