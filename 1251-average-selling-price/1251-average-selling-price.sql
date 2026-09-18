select t1.product_id , coalesce(ROUND(SUM(t1.price * t2.units)/SUM(t2.units), 2) , 0) as average_price
from prices t1 
left join UnitsSold t2
ON t1.product_id = t2.product_id
AND t2.purchase_date between t1.start_date and t1.end_date
group by t1.product_id