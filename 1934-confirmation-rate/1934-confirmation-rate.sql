# Write your MySQL query statement below
SELECT t1.user_id , ROUND((COUNT(CASE WHEN  t2.action = 'confirmed' THEN 1 END)/(COUNT(*))),2) as confirmation_rate 
FROM Signups t1 
LEFT JOIN Confirmations t2
ON t1.user_id = t2.user_id
GROUP BY t1.user_id