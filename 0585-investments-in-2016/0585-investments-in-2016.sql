# Write your MySQL query statement below
select ROUND(sum(tiv_2016) , 2)  as tiv_2016   from
Insurance t1
Where (select count(tiv_2015)  from Insurance where tiv_2015= t1.tiv_2015) >1
and (select sum(lat=t1.lat and lon=t1.lon) from Insurance) <=1;