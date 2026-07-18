# Write your MySQL query statement below
WITH CTE AS (
    SELECT E.id AS id, 
           E.name AS Employee, 
           E.salary AS Salary, 
           D.name AS Department
    FROM Employee E
    LEFT JOIN Department D
    ON E.departmentId = D.id
),

CTE2 AS (
    SELECT id, Employee, Salary, Department, 
           DENSE_RANK() OVER (Partition BY Department ORDER BY Salary Desc) AS rnk
    FROM CTE 
)

SELECT Department, Employee, Salary
FROM CTE2
WHERE rnk <= 3
ORDER BY Department, rnk