# Write your MySQL query statement below
WITH CTE AS(
    SELECT employee_id, COUNT(*) AS cnt
    FROM Employee
    GROUP BY employee_id
)
SELECT E.employee_id, E.department_id
FROM Employee E LEFT JOIN CTE
ON E.employee_id = CTE.employee_id
WHERE (CTE.cnt = 1 AND E.primary_flag = 'N') OR (CTE.cnt > 1 AND E.primary_flag = 'Y')
