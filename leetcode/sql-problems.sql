-- combine-two-tables
SELECT Person.firstName, Person.lastName, Address.city, Address.state FROM Person
LEFT JOIN Address ON Person.personId = Address.personId
-- employees-earning-more-than-their-managers
SELECT E.name FROM Employee E, Employee M
WHERE E.managerId IS NOT NULL AND M.id = E.managerId AND E.salary > M.salary
-- duplicate-emails
SELECT email FROM Person GROUP BY email HAVING COUNT(*) > 1 
-- customers-who-never-order
SELECT name as Customers FROM Customers C 
WHERE NOT EXISTS ( SELECT 1 FROM Orders O WHERE C.id = O.customerId )
-- delete-duplicate-emails
DELETE P1 FROM Person P1, Person P2 WHERE P1.email = P2.email AND P1.Id > P2.Id