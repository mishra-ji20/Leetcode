# Write your MySQL query statement below
select employee_id from employees where employees.employee_id not in(select employee_id from salaries) 
union
select employee_id from salaries where salaries.employee_id not in(select employee_id from employees)
order by 1;