# Write your MySQL query statement below
select employee_id,if(mod(employee_id,2)=1 and left(name,1) not in ('M'),salary,0) as bonus from employees order by employee_id;