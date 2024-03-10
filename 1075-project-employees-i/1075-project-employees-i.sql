# Write your MySQL query statement below

Select proj.project_id,round(avg(emp.experience_years),2) as average_years from Project proj inner join Employee emp
on proj.employee_id=emp.employee_id
Group by (proj.project_id);