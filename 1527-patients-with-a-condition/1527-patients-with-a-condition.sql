# Write your MySQL query statement below
select * from Patients
where (
    LENGTH(conditions) >=5 &&
    SUBSTR(conditions  ,1 , 5) = 'DIAB1'
)
or conditions like '% DIAB1%'