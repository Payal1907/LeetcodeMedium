SELECT E1.name 
FROM
Employee AS E2
JOIN
Employee AS E1
ON 
E2.managerId=E1.id
GROUP BY E1.name,E2.managerId
HAVING COUNT(*)>=5;

