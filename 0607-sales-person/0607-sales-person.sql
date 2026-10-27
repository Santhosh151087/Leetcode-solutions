SELECT name from SalesPerson 
WHERE sales_id not in 
 (
    select sales_id from Orders 
    WHERE com_id in (
        SELECT com_id from Company 
WHERE name = 'RED'
    )
);