select visited_on , amount ,average_amount from (
    select DISTINCT visited_on , sum(amount) over (
        ORDER BY Visited_on 
        RANGE BETWEEN  INTERVAL 6 DAY PRECEDING  AND CURRENT ROW) as amount,
        ROUND(sum(amount) over (
            order by Visited_on 
            RANGE BETWEEN INTERVAL 6 DAY PRECEDING and CURRENT ROW 
        ) /7 , 2) as average_amount
        from Customer
) as Whole
where DATEDIFF(visited_on , (select min(visited_on) from Customer)) >=6