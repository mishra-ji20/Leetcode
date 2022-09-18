# Write your MySQL query statement below
select department.name as Department,employee.name as Employee ,employee.salary from department,employee 
where employee.salary=(select max(salary) from employee where employee.departmentId =department.id) and employee.departmentId=department.Id;