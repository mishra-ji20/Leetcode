# Write your MySQL query statement below
Select employee_id from Employees emp where salary<30000 and manager_id is not null and manager_id 
not in(Select distinct employee_id from Employees) order by employee_id;