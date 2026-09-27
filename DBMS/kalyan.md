# DBMS Notes

These are my DBMS notes in simple words. I am keeping the main ideas, examples, and interview points together so I can revise from one place.

---

# 1. Data, Information, Database and DBMS

## Data

- Data = raw facts.
- By itself, raw data may not give a useful meaning.
- Examples:
  - `101, Kalyan, 20`
  - `50000`
  - `Lucknow`
- Data can be quantitative or qualitative.

### Quantitative data

- Numerical data.
- Example: age = 20, salary = 50000, marks = 87.

### Qualitative data

- Descriptive data.
- Example: city = Lucknow, feedback = good.

## Information

- Information = processed/organized data that gives meaning.
- Example:
  - Data: `87, 91, 78`
  - Information: `Average marks = 85.3`

## Database

- Database = organized collection of related data.
- Main idea is not just storing data, but storing it so that we can search, update and manage it easily.

## DBMS

- DBMS = Database Management System.
- It is software used to create, store, retrieve, update and manage data in a database.
- It acts as a layer between the application/user and the database.

Examples:

- MySQL
- PostgreSQL
- Oracle Database
- SQL Server
- SQLite
- MongoDB

### Basic operations

- Create
- Read
- Update
- Delete

These are commonly called CRUD operations.

---

# 2. File System vs DBMS

Before DBMS, applications often stored data in separate files.

## Problems with the file system

- Data redundancy
- Data inconsistency
- Difficult sharing
- Difficult concurrent access
- Weak security control
- Difficult backup and recovery
- Program-data dependency
- Difficult to run complex queries

### Example

Suppose a college stores student details in separate files:

```text
students.txt
fees.txt
hostel.txt
library.txt
```

The same student name and phone number may appear in many files.

If the phone number changes, every file may have to be updated.

This creates inconsistency risk.

## DBMS advantages

- Centralized data management
- Less redundancy through proper design
- Better consistency
- Concurrent access
- Security and authorization
- Backup and recovery
- Integrity constraints
- Transactions
- Query support
- Data independence

### Important correction

- Centralization does not automatically mean there are zero duplicates.
- Proper database design and normalization are used to reduce unnecessary redundancy.

---

# 3. Why DBMS is used

Main goals of DBMS:

1. Store large amounts of data.
2. Retrieve data efficiently.
3. Allow multiple users to work at the same time.
4. Keep data correct and consistent.
5. Provide security.
6. Recover data after failures.
7. Hide low-level storage details from users/applications.

---

# 4. DBMS Abstraction and 3-Schema Architecture

A DBMS hides physical storage details from users.

The standard 3-schema architecture has 3 levels.

## 1. Internal level / Physical level

- Lowest level.
- Describes how data is physically stored.
- Includes things like files, pages, indexes and storage structures.

Example:

```text
Which disk page contains the record?
Which blocks are used?
Is a B+ tree index used?
```

## 2. Conceptual level / Logical level

- Middle level.
- Describes the complete logical structure of the database.
- Tables, attributes, relationships and constraints are defined here.

Example:

```text
Student(student_id, name, dept_id)
Department(dept_id, dept_name)
```

## 3. External level / View level

- Highest level.
- Closest to users.
- Different users can get different views of the same database.

Example:

- Student sees marks and attendance.
- Accountant sees fees.
- HR sees employee salary details.

### Easy example

Think of a restaurant:

- Internal level = kitchen and storage details.
- Conceptual level = complete restaurant blueprint.
- External level = what a customer sees on the menu/table.

---

# 5. Data Independence

Data independence means we can change one level of the database without forcing changes at the next higher level.

## Physical data independence

- Change physical storage without changing logical schema.

Example:

```text
Old: heap file
New: B+ tree index + different storage layout
```

The application tables can remain the same.

## Logical data independence

- Change the logical schema without changing external views/programs as much as possible.

Example:

```text
Add a new column to Employee
```

Existing views may continue to work.

### Which is harder?

- Logical data independence is generally harder to achieve than physical data independence.

---

# 6. Schema vs Instance

## Schema

- Structure/design of the database.
- Changes less frequently.
- Think of it as a blueprint.

Example:

```text
Student(id, name, age)
```

## Instance

- Actual data present in the database at a particular time.
- Changes frequently.

Example:

```text
1, Kalyan, 20
2, Ravi, 21
```

---

# 7. Data Models

A data model gives a way to describe:

- Data
- Relationships
- Constraints
- Meaning/structure of data

Common data models:

1. Hierarchical model
2. Network model
3. Relational model
4. ER model
5. Object-oriented model
6. NoSQL models

---

# 8. Database Users and DBA

## DBA - Database Administrator

DBA is responsible for managing the database system.

Typical responsibilities:

- User management
- Authorization
- Backup and recovery
- Performance tuning
- Storage management
- Monitoring
- Security
- Database availability

Other users include:

- Application programmers
- Database designers
- End users
- Data analysts

---

# 9. Database Languages

## DDL - Data Definition Language

Used to define/change database structure.

Commands:

```sql
CREATE
ALTER
DROP
TRUNCATE
```

Example:

```sql
CREATE TABLE Student (
    id INT PRIMARY KEY,
    name VARCHAR(50)
);
```

## DML - Data Manipulation Language

Used to insert/update/delete data.

Commands:

```sql
INSERT
UPDATE
DELETE
```

## DQL - Data Query Language

Usually used to refer to retrieving data.

```sql
SELECT
```

Different books group `SELECT` under DML, so the classification can vary.

## DCL - Data Control Language

Used for permissions.

```sql
GRANT
REVOKE
```

## TCL - Transaction Control Language

Used for transaction control.

```sql
COMMIT
ROLLBACK
SAVEPOINT
```

---

# 10. How an Application Talks to a Database

Typical flow:

```text
Application
    ↓
DB driver / API
    ↓
DBMS
    ↓
Database
```

Examples of drivers/interfaces:

- JDBC for Java
- ODBC for generic database connectivity
- Language-specific database libraries

Example:

```text
Java application
    ↓
JDBC
    ↓
MySQL server
    ↓
Result
```

---

# 11. Database Application Architectures

## 1-Tier

Everything runs on one machine.

```text
User + Application + Database
```

Example:

- Local SQLite application
- Local database tool

Simple but not good for large multi-user systems.

## 2-Tier

```text
Client
   ↓
Database Server
```

Client contains UI/application logic and communicates directly with DB server.

## 3-Tier

```text
Client
   ↓
Application Server
   ↓
Database Server
```

### Layer 1 - Presentation

UI/client.

### Layer 2 - Application

Business logic, validation, authentication.

### Layer 3 - Database

Stores and retrieves data.

### Why 3-tier?

- Better security
- Easier maintenance
- Easier scaling
- Client does not directly access the database

---

# 12. ER Model

ER = Entity Relationship model.

It is a high-level conceptual model used to represent real-world objects and relationships.

It is usually drawn using an ER diagram.

## Entity

An entity is a real-world object that can be identified.

Examples:

- Student
- Employee
- Loan
- Department

## Entity Set

Collection of similar entities.

Example:

```text
Student entity set = all students
```

---

# 13. Strong Entity and Weak Entity

## Strong Entity

- Has its own key.
- Can be identified independently.

Example:

```text
Employee(emp_id, name, salary)
```

`emp_id` identifies the employee.

## Weak Entity

- Does not have a complete key of its own.
- Depends on an owner/strong entity.
- Uses a partial key together with the owner's key.

Example:

```text
Employee(emp_id)
Dependent(dependent_name, age)
```

A dependent may be identified by:

```text
(emp_id, dependent_name)
```

The owner entity participates totally in the identifying relationship.

---

# 14. Attributes in ER Model

An attribute describes a property of an entity.

Example:

```text
Student → id, name, age, phone
```

## Simple attribute

Cannot be divided further.

Example:

```text
age
salary
```

## Composite attribute

Can be divided into smaller attributes.

Example:

```text
Name → first_name, middle_name, last_name
```

## Single-valued attribute

One value for one entity.

Example:

```text
student_id
```

## Multivalued attribute

Can have multiple values.

Example:

```text
phone_numbers = {9876..., 8765...}
```

## Derived attribute

Can be calculated from another attribute.

Example:

```text
DOB → Age
```

Age is usually derived from date of birth.

## Null

NULL does not simply mean zero or empty string.

It can represent cases such as:

- Unknown
- Not applicable
- Not yet provided

---

# 15. Relationship

Relationship = association between entities.

Examples:

```text
Student ── enrolls ── Course
Employee ── works_in ── Department
Customer ── places ── Order
```

A relationship can also have attributes.

Example:

```text
Student -- enrolls -- Course
                 |
               grade
```

---

# 16. Cardinality / Mapping Cardinality

Cardinality tells how many entities can participate in a relationship.

## 1 : 1

One entity on one side is related to at most one entity on the other side.

Example:

```text
Person ↔ Passport
```

## 1 : N

One entity on one side can relate to many entities on the other side.

Example:

```text
Department → Employees
```

One department can have many employees.

## N : 1

Many entities on one side relate to one entity on the other side.

Example:

```text
Employees → Department
```

## M : N

Many entities on both sides.

Example:

```text
Student ↔ Course
```

A student can take many courses and a course can have many students.

---

# 17. Participation Constraints

Participation tells whether participation is mandatory.

## Partial participation

Some entities may not participate.

Example:

```text
Employee -- manages -- Department
```

Not every employee must manage a department.

## Total participation

Every entity must participate.

Example:

```text
Dependent must belong to an Employee.
```

A weak entity has total participation in its identifying relationship.

### Cardinality vs Participation

- Cardinality = maximum number of related entities.
- Participation = minimum participation requirement.

This distinction is important.

---

# 18. EER Model

EER = Enhanced Entity Relationship model.

Used when the basic ER model is not enough.

Main concepts:

- Specialization
- Generalization
- Inheritance
- Aggregation

## Specialization

Top-down approach.

One supertype is divided into subtypes.

```text
Person
 /    \
Student Teacher
```

Common attributes remain in `Person`.

Specific attributes go to subclasses.

## Generalization

Bottom-up approach.

Combine similar lower-level entities into a common supertype.

```text
Car
Bus
 ↓
Vehicle
```

## Attribute inheritance

Subclasses inherit attributes of the superclass.

## Relationship inheritance

Subclasses can inherit relationships of the superclass depending on the model.

## Disjoint vs Overlapping

### Disjoint

An entity can belong to only one subclass.

Example:

```text
Employee → FullTime OR PartTime
```

### Overlapping

An entity can belong to multiple subclasses.

Example:

```text
Person → Student + Employee
```

## Total vs Partial specialization

### Total

Every superclass entity must belong to at least one subclass.

### Partial

Some superclass entities may belong to no subclass.

## Aggregation

Treat a relationship as a higher-level entity so that it can participate in another relationship.

Think:

```text
Employee -- works_on -- Project
               
             monitored_by
```

The `works_on` relationship itself may need to participate in another relationship.

---

# 19. Relational Model

Relational model stores data in relations/tables.

A table contains:

- Rows = tuples
- Columns = attributes

Example:

```text
Student
+----+--------+-----+
| id | name   | age |
+----+--------+-----+
| 1  | Kalyan | 20  |
| 2  | Ravi   | 21  |
+----+--------+-----+
```

## Relation schema

Defines table structure.

```text
Student(id, name, age)
```

## Relation instance

Actual rows at a specific moment.

## Degree

Number of attributes/columns.

## Cardinality

Number of tuples/rows.

---

# 20. Properties of a Relation

In the classical relational model:

- Each cell contains an atomic value.
- Values come from defined domains.
- Attribute names are unique within a relation.
- Tuple order has no logical meaning.
- Attribute order has no logical meaning.
- Duplicate tuples are not part of the mathematical relation model.

SQL tables can technically contain duplicate rows unless constraints or `DISTINCT` prevent them.

---

# 21. Keys in Relational Model

## Super Key

Any set of attributes that uniquely identifies a tuple.

Example:

```text
Student(id, name, email)
```

If `id` is unique:

```text
{id}
{id, name}
{id, email}
{id, name, email}
```

are all superkeys.

## Candidate Key

A minimal superkey.

No unnecessary attribute can be removed.

If both `id` and `email` are unique:

```text
{id}
{email}
```

can be candidate keys.

## Primary Key

One candidate key chosen as the main identifier.

Properties:

- Unique
- Not NULL
- One primary key constraint per table

A primary key can contain multiple columns.

## Alternate Key

Candidate key that was not selected as primary key.

## Foreign Key

Attribute(s) in one relation that refer to a candidate/primary key of another relation.

Example:

```text
Department(dept_id PK, dept_name)
Student(student_id PK, name, dept_id FK)
```

`Student.dept_id` refers to `Department.dept_id`.

## Composite Key

A key containing multiple attributes.

Example:

```text
Enrollment(student_id, course_id)
```

The combination may be the primary key.

## Compound Key

In many interview contexts this term is used for a key made from multiple attributes, often foreign keys. Terminology can overlap with composite key.

## Surrogate Key

Artificial key generated only to identify a row.

Example:

```text
id = 101, 102, 103...
```

It has no business meaning.

---

# 22. Integrity Constraints

Integrity constraints keep data valid.

## Domain Constraint

Value must belong to an allowed domain.

Example:

```sql
age INT CHECK (age >= 0)
```

## Entity Integrity

Primary key cannot be NULL.

## Referential Integrity

Foreign key must either:

- Match a referenced key value, or
- Be NULL when NULL is allowed.

Example:

```sql
FOREIGN KEY (dept_id) REFERENCES Department(dept_id)
```

## NOT NULL

Column cannot contain NULL.

## UNIQUE

Prevents duplicate non-NULL values according to DBMS rules.

## DEFAULT

Uses a default value when a value is not supplied.

## CHECK

Enforces a condition.

---

# 23. Primary Key vs UNIQUE

| Primary Key | UNIQUE |
|---|---|
| Uniquely identifies row | Enforces uniqueness on column(s) |
| Cannot be NULL | NULL handling depends on DBMS |
| One primary key constraint per table | Multiple UNIQUE constraints possible |

---

# 24. ER Model to Relational Model

## Strong entity

Create one table.

Example:

```text
Student(id, name, age)
```

Primary key of entity becomes primary key of table.

## Weak entity

Create a separate table.

Include:

- Weak entity attributes
- Owner primary key as foreign key
- Partial key

Primary key becomes:

```text
(owner_key + partial_key)
```

## Composite attribute

Break it into simple attributes.

```text
Name → first_name, last_name
```

## Multivalued attribute

Create a separate table.

Example:

```text
Student(student_id, name)
StudentPhone(student_id, phone)
```

Primary key can be:

```text
(student_id, phone)
```

## Derived attribute

Usually not stored unless there is a specific performance reason.

## 1:1 relationship

Can place the foreign key in one of the two tables, usually where participation/design makes more sense.

## 1:N relationship

Put the primary key of the 1-side as a foreign key in the N-side table.

Example:

```text
Department(dept_id)
Employee(emp_id, dept_id)
```

## M:N relationship

Create a new relation containing the primary keys of both entities.

Example:

```text
Student(student_id)
Course(course_id)
Enrollment(student_id, course_id)
```

If the relationship has attributes, include them too.

Example:

```text
Enrollment(student_id, course_id, grade)
```

---

# 25. Relational Algebra

Relational algebra is a formal query language used to describe operations on relations.

Important operators:

- Selection
- Projection
- Union
- Set difference
- Cartesian product
- Rename
- Join

## Selection - σ

Filters rows.

Example:

```text
σ age > 20 (Student)
```

Means: select students whose age is greater than 20.

## Projection - π

Selects columns.

```text
π name, age (Student)
```

Means: only return `name` and `age`.

## Union - ∪

Combines tuples from two union-compatible relations.

```text
A ∪ B
```

## Set Difference - −

Rows present in A but not in B.

```text
A − B
```

## Cartesian Product - ×

Every tuple of A is paired with every tuple of B.

If A has 3 rows and B has 4 rows:

```text
A × B = 12 rows
```

## Rename - ρ

Used to rename a relation or attributes.

## Join

Combines related tuples.

Common conceptual forms:

- Theta join
- Equijoin
- Natural join
- Outer joins

---

# 26. SQL Basics

## Create table

```sql
CREATE TABLE Student (
    id INT PRIMARY KEY,
    name VARCHAR(50),
    age INT,
    dept_id INT
);
```

## Insert

```sql
INSERT INTO Student(id, name, age, dept_id)
VALUES (1, 'Kalyan', 20, 10);
```

## Select

```sql
SELECT *
FROM Student;
```

## Select specific columns

```sql
SELECT name, age
FROM Student;
```

## WHERE

```sql
SELECT *
FROM Student
WHERE age >= 20;
```

## UPDATE

```sql
UPDATE Student
SET age = 21
WHERE id = 1;
```

## DELETE

```sql
DELETE FROM Student
WHERE id = 1;
```

---

# 27. SQL Clauses

## DISTINCT

Removes duplicate result values.

```sql
SELECT DISTINCT dept_id
FROM Student;
```

## ORDER BY

Sort result.

```sql
SELECT *
FROM Student
ORDER BY age DESC;
```

## GROUP BY

Groups rows for aggregate calculations.

```sql
SELECT dept_id, COUNT(*)
FROM Student
GROUP BY dept_id;
```

## HAVING

Filters groups after grouping.

```sql
SELECT dept_id, COUNT(*) AS cnt
FROM Student
GROUP BY dept_id
HAVING COUNT(*) > 10;
```

### WHERE vs HAVING

- `WHERE` filters rows before grouping.
- `HAVING` filters groups after grouping.

---

# 28. SQL Aggregate Functions

Common functions:

```text
COUNT()
SUM()
AVG()
MIN()
MAX()
```

Example:

```sql
SELECT AVG(salary)
FROM Employee;
```

Important:

- `COUNT(*)` counts rows.
- `COUNT(column)` generally ignores NULL values.

---

# 29. SQL Joins

Suppose:

```text
Employee
id | name | dept_id
1  | A    | 10
2  | B    | 20
3  | C    | 30

Department
dep_id | dept_name
10     | CSE
20     | ECE
40     | ME
```

## INNER JOIN

Returns matching rows from both tables.

```sql
SELECT e.name, d.dept_name
FROM Employee e
JOIN Department d
  ON e.dept_id = d.dep_id;
```

Result conceptually:

```text
A CSE
B ECE
```

## LEFT JOIN

All rows from left table + matching rows from right.

No match → NULL on right side.

## RIGHT JOIN

All rows from right table + matching rows from left.

## FULL OUTER JOIN

All rows from both sides.

Unmatched side gets NULL.

## CROSS JOIN

All combinations.

If A has 3 rows and B has 4 rows:

```text
3 × 4 = 12 rows
```

## SELF JOIN

A table joined with itself.

Example:

```text
Employee(emp_id, name, manager_id)
```

Find employee + manager using a self join.

---

# 30. Subqueries

A query inside another query.

Example:

```sql
SELECT name
FROM Employee
WHERE salary > (
    SELECT AVG(salary)
    FROM Employee
);
```

## Correlated subquery

Subquery depends on the outer query row.

It may conceptually execute once for each outer row.

## EXISTS

Checks whether a subquery returns at least one row.

```sql
SELECT e.name
FROM Employee e
WHERE EXISTS (
    SELECT 1
    FROM Department d
    WHERE d.dep_id = e.dept_id
);
```

---

# 31. UNION, INTERSECT, EXCEPT

These are set operations.

Relations must be union-compatible.

## UNION

Combines results and removes duplicates.

## UNION ALL

Combines results and keeps duplicates.

## INTERSECT

Common rows.

## EXCEPT

Rows in first query but not in second.

Support depends on the SQL database.

---

# 32. Views

A view is a virtual table created from a query.

Example:

```sql
CREATE VIEW CSE_Students AS
SELECT id, name
FROM Student
WHERE dept_id = 10;
```

Advantages:

- Security
- Simpler queries
- Abstraction
- Reusable logic

## Materialized View

Stores the query result physically.

It can make read queries faster, but it must be refreshed when base data changes.

---

# 33. Functional Dependency

Functional dependency describes a relationship between attributes.

```text
X → Y
```

Means:

For any two tuples, if they have the same value of X, they must have the same value of Y.

Think:

```text
X determines Y
```

Example:

```text
student_id → student_name
```

If student ID is unique, knowing `student_id` determines `student_name`.

## Determinant

Left side of FD.

```text
X → Y
```

`X` is determinant.

## Dependent

Right side of FD.

`Y` is dependent.

---

# 34. Types of Functional Dependency

## Trivial FD

If:

```text
Y ⊆ X
```

then:

```text
X → Y
```

is trivial.

Examples:

```text
A → A
AB → A
ABC → BC
```

## Non-trivial FD

If Y is not a subset of X.

Example:

```text
A → B
```

## Completely non-trivial FD

X and Y have no common attributes.

Example:

```text
A → B
```

---

# 35. Armstrong's Axioms

Basic rules for deriving functional dependencies.

## Reflexivity

If:

```text
Y ⊆ X
```

then:

```text
X → Y
```

## Augmentation

If:

```text
X → Y
```

then:

```text
XZ → YZ
```

Adding the same attributes to both sides preserves the dependency.

## Transitivity

If:

```text
X → Y
Y → Z
```

then:

```text
X → Z
```

### Some derived rules

## Union

If:

```text
X → Y
X → Z
```

then:

```text
X → YZ
```

## Decomposition

If:

```text
X → YZ
```

then:

```text
X → Y
X → Z
```

## Pseudo-transitivity

If:

```text
X → Y
WY → Z
```

then:

```text
WX → Z
```

---

# 36. Attribute Closure

Closure of X under F is written as:

```text
X+
```

It contains all attributes that can be functionally determined by X using the given FDs.

## Example

Relation:

```text
R(A, B, C, D)
```

FDs:

```text
A → B
B → C
AC → D
```

Find `A+`.

Start:

```text
A+ = {A}
```

From `A → B`:

```text
A+ = {A, B}
```

From `B → C`:

```text
A+ = {A, B, C}
```

Now `AC → D` can be applied:

```text
A+ = {A, B, C, D}
```

So A is a candidate key if A is minimal.

---

# 37. Candidate Key using Closure

To check whether X is a key:

1. Compute X+.
2. If X+ contains all attributes of relation, X is a superkey.
3. Check minimality. If no attribute can be removed while still determining all attributes, it is a candidate key.

---

# 38. Normalization

Normalization = organizing relations to reduce unnecessary redundancy and avoid anomalies.

Main goals:

- Reduce redundancy
- Avoid insertion anomaly
- Avoid deletion anomaly
- Avoid update anomaly
- Improve consistency

Normalization is not simply "making more tables". It is based on dependencies and good relation design.

---

# 39. Anomalies

Suppose:

```text
StudentCourse(student_id, student_name, course_id, course_name, instructor)
```

Same course information may repeat for many students.

## Insertion anomaly

Cannot insert some information without unrelated information.

Example:

Cannot add a new course until at least one student is enrolled if the design forces one combined row.

## Deletion anomaly

Deleting one row can accidentally remove the only stored information about another entity.

Example:

Deleting the last student from a course may also remove course information.

## Update anomaly

Same value appears in many rows, so one logical change requires many updates.

Example:

Changing instructor name in 50 rows.

If one row is missed, data becomes inconsistent.

---

# 40. Prime and Non-prime Attributes

## Prime attribute

An attribute that belongs to at least one candidate key.

## Non-prime attribute

An attribute that belongs to no candidate key.

These terms are important for 2NF and 3NF.

---

# 41. First Normal Form - 1NF

A relation is in 1NF when each cell contains an atomic/single value according to the chosen domain.

Bad design:

```text
Student | Phones
Kalyan  | 9876, 8765
```

Better:

```text
Student
id | name
1  | Kalyan

StudentPhone
id | phone
1  | 9876
1  | 8765
```

1NF mainly removes repeating groups / non-atomic values.

---

# 42. Second Normal Form - 2NF

A relation is in 2NF when:

1. It is in 1NF.
2. No non-prime attribute is partially dependent on a proper subset of a candidate key.

Partial dependency matters when a candidate key has more than one attribute.

## Example

```text
Enrollment(student_id, course_id, student_name, course_name, grade)
```

Assume key:

```text
(student_id, course_id)
```

Dependencies:

```text
student_id → student_name
course_id → course_name
(student_id, course_id) → grade
```

`student_name` depends only on `student_id`.

`course_name` depends only on `course_id`.

So there are partial dependencies.

### Split

```text
Student(student_id, student_name)
Course(course_id, course_name)
Enrollment(student_id, course_id, grade)
```

---

# 43. Third Normal Form - 3NF

A relation is in 3NF if for every non-trivial FD:

```text
X → A
```

at least one is true:

- X is a superkey, or
- A is a prime attribute.

For simpler interview language:

- Relation should be in 2NF.
- Non-key attributes should not depend on another non-key attribute in a way that creates transitive dependency.

## Example

```text
Student(student_id, student_name, dept_id, dept_name)
```

Dependencies:

```text
student_id → student_name, dept_id
dep_id → dept_name
```

Therefore:

```text
student_id → dept_id → dept_name
```

`dept_name` depends transitively on `student_id`.

### Split

```text
Student(student_id, student_name, dept_id)
Department(dept_id, dept_name)
```

---

# 44. BCNF

BCNF = Boyce-Codd Normal Form.

For every non-trivial FD:

```text
X → Y
```

X must be a superkey.

BCNF is stricter than 3NF.

### Important point

A relation can satisfy 3NF but still violate BCNF.

This usually happens when there are multiple overlapping candidate keys and a determinant that is not a superkey.

---

# 45. 4NF

4NF deals with multivalued dependencies.

A relation is in 4NF when for every non-trivial multivalued dependency:

```text
X →→ Y
```

X is a superkey.

### Example idea

Suppose:

```text
Student(student, skill, hobby)
```

Skills and hobbies are independent multivalued facts.

One student may have:

```text
Skills = {C++, Java}
Hobbies = {Music, Cricket}
```

Storing both in one table creates combinations:

```text
C++ + Music
C++ + Cricket
Java + Music
Java + Cricket
```

Better separate the independent multivalued facts.

---

# 46. 5NF

5NF is mainly about join dependencies.

A relation is in 5NF when every non-trivial join dependency is implied by candidate keys.

It is less common in normal interview discussions than 1NF, 2NF, 3NF and BCNF.

---

# 47. Normalization vs Denormalization

## Normalization

- Reduces redundancy
- Better consistency
- Easier updates
- May increase number of joins

## Denormalization

Intentionally stores some duplicate data to improve read performance or simplify queries.

Example:

Instead of joining `Order` with `Customer` every time, a system may store `customer_name` with order data if that trade-off is justified.

### Important

Denormalization is a design trade-off, not automatically a bad practice.

---

# 48. Lossless Decomposition

When we split one relation into multiple relations, joining them back should not create false tuples.

Such a decomposition is called lossless/lossless-join decomposition.

Simple idea:

```text
Original table
    ↓ split
R1 + R2
    ↓ natural join
Original information
```

No spurious rows should appear.

---

# 49. Dependency Preservation

A decomposition is dependency preserving if we can enforce the important functional dependencies by looking at the decomposed relations without needing expensive joins.

A good normalization design often tries to achieve both:

- Lossless join
- Dependency preservation

---

# 50. Transaction

A transaction is a logical unit of work.

Example: money transfer.

```text
T1:
1. Debit ₹100 from A
2. Credit ₹100 to B
```

Both should happen together.

If the system fails after debit but before credit, recovery must prevent an incorrect final state.

---

# 51. ACID Properties

## Atomicity

All operations of a transaction happen, or none of them happen.

Example:

```text
Debit + Credit
```

Both together.

## Consistency

A transaction takes the database from one valid state to another valid state while preserving declared rules/constraints.

## Isolation

Concurrent transactions should not incorrectly interfere with each other.

The result should correspond to an allowed ordering/isolation behavior.

## Durability

After commit, the committed result should survive a crash according to the system's durability guarantees.

---

# 52. Transaction States

Typical states:

```text
Active
  ↓
Partially Committed
  ↓
Committed
  ↓
Terminated
```

Failure path:

```text
Active → Failed → Aborted → Terminated
```

## Active

Transaction is executing.

## Partially committed

Last statement has executed, but commit is not fully guaranteed yet.

## Committed

Commit is completed and transaction's effects are durable according to the DBMS protocol.

## Failed

Transaction cannot continue normally.

## Aborted

Its effects are undone or otherwise removed according to recovery rules.

## Terminated

Transaction has finished its lifecycle.

---

# 53. Schedule

A schedule is the order in which operations from multiple transactions are executed.

Example:

```text
T1: R(A), W(A)
T2: R(A), W(A)
```

A schedule may interleave these operations.

## Serial schedule

One transaction completes before another begins.

```text
T1 → T2
```

Easy to reason about, but may reduce concurrency.

## Non-serial schedule

Operations are interleaved.

Can improve performance, but needs concurrency control.

---

# 54. Conflict Operations

Two operations conflict if:

1. They belong to different transactions.
2. They access the same data item.
3. At least one operation is a write.

Conflict pairs:

- Read-Write
- Write-Read
- Write-Write

Read-Read does not create a conflict.

---

# 55. Conflict Serializability

A non-serial schedule is conflict-serializable if it is conflict-equivalent to some serial schedule.

## Precedence Graph

Steps:

1. Create one node per transaction.
2. Add edge `Ti → Tj` when an operation of Ti conflicts with an operation of Tj and Ti's operation occurs first.
3. If the graph is acyclic, the schedule is conflict-serializable.

Example:

```text
T1: W(A)
T2: R(A)
```

Since T1 writes before T2 reads:

```text
T1 → T2
```

No cycle means serializable for this simple case.

---

# 56. View Serializability

View serializability is more general than conflict serializability.

A schedule is view-serializable if it is view-equivalent to a serial schedule.

Every conflict-serializable schedule is view-serializable.

But some view-serializable schedules are not conflict-serializable.

---

# 57. Problems in Concurrent Transactions

## Lost Update

Two transactions read the same old value and one update overwrites the other.

Example:

```text
Initial A = 100
T1 reads 100
T2 reads 100
T1 writes 120
T2 writes 130
```

T1's update is lost.

## Dirty Read

Transaction reads data written by another transaction that has not committed.

## Non-repeatable Read

A transaction reads the same row twice and gets different committed values because another transaction updated it in between.

## Phantom Read

A repeated query returns a different set of rows because another transaction inserted/deleted matching rows.

## Incorrect Summary / Inconsistent Analysis

An aggregate query sees a mix of old and new values during concurrent updates.

---

# 58. Recoverable Schedule

If T2 reads data written by T1, T2 should not commit before T1 commits.

This prevents a dependent transaction from committing based on data from a transaction that later aborts.

---

# 59. Cascading Rollback

If a transaction reads uncommitted data from another transaction and that transaction aborts, the dependent transaction may also need to abort.

This can cause a chain of rollbacks.

## Cascadeless schedule

Transactions read only committed data.

So dirty reads are avoided.

## Strict schedule

If a transaction writes X, no other transaction can read or write X until the first transaction commits/aborts.

Strict schedules make recovery easier.

---

# 60. Lock-Based Concurrency Control

A lock controls access to a data item.

## Shared Lock - S

Used for reading.

Multiple transactions can hold shared locks on the same item.

## Exclusive Lock - X

Used for writing.

Only one transaction can hold an exclusive lock on an item, and it conflicts with shared locks too.

### Compatibility

| Existing | New S | New X |
|---|---:|---:|
| S | Yes | No |
| X | No | No |

---

# 61. Two-Phase Locking - 2PL

Two-phase locking has two phases.

## Growing phase

Transaction can acquire locks.

It cannot release locks.

## Shrinking phase

Transaction releases locks.

It cannot acquire new locks.

2PL guarantees conflict serializability.

But it can cause deadlocks.

---

# 62. Strict 2PL

In strict 2PL, exclusive locks are held until commit or abort.

Advantages:

- Prevents dirty writes.
- Simplifies recovery.
- Produces strict schedules.

---

# 63. Conservative / Static 2PL

Transaction obtains all required locks before it starts executing.

Advantage:

- Deadlock can be avoided.

Disadvantage:

- Need to know all required data items in advance.

---

# 64. Deadlock

Deadlock happens when transactions wait for each other forever.

Example:

```text
T1 holds A and waits for B
T2 holds B and waits for A
```

Cycle:

```text
T1 → T2 → T1
```

---

# 65. Deadlock Handling

## Prevention

Force rules so a deadlock cannot form.

Common timestamp-based ideas:

### Wait-Die

Older transaction may wait.

Younger transaction may abort instead of waiting in the relevant case.

### Wound-Wait

Older transaction can force a younger transaction to abort in the relevant case.

The exact rule is based on timestamps, so remember the age direction carefully.

## Detection

Use a wait-for graph.

If there is a cycle, there is a deadlock.

## Recovery

Abort one or more transactions and release their locks.

### Starvation

A transaction may keep getting delayed or aborted and never make progress.

A good deadlock strategy should also consider starvation.

---

# 66. Timestamp Ordering

Each transaction gets a timestamp.

The DBMS uses timestamps to decide whether an operation is allowed.

No traditional lock is required for basic timestamp ordering.

Goal:

```text
Maintain an order consistent with transaction timestamps.
```

Advantage:

- No lock deadlock.

Disadvantage:

- More transaction aborts may happen.

---

# 67. Optimistic Concurrency Control

Used when conflicts are expected to be low.

Basic idea:

1. Read/execute without heavy locking.
2. Validate before commit.
3. Commit if validation succeeds.
4. Otherwise abort/retry.

Useful in workloads where contention is usually low.

---

# 68. MVCC

MVCC = Multi-Version Concurrency Control.

The DBMS keeps multiple versions of data.

Readers can often read an older consistent version while writers create a newer version.

Benefits:

- Good read concurrency
- Readers can avoid blocking writers in many systems
- Useful for snapshot-style reads

Implementation details differ across DBMSs.

---

# 69. Isolation Levels

Common SQL isolation levels:

1. Read Uncommitted
2. Read Committed
3. Repeatable Read
4. Serializable

## Read Uncommitted

Lowest isolation.

Dirty reads may be possible.

## Read Committed

Only committed data is normally read.

Dirty reads are prevented.

Non-repeatable reads may still occur.

## Repeatable Read

Repeated reads of the same rows are protected according to the DBMS's implementation.

Phantom behavior depends on the database implementation/isolation model.

## Serializable

Strongest standard SQL isolation level.

The result is equivalent to some serial execution.

### Important

Actual behavior of each isolation level can vary somewhat by DBMS because different systems use different concurrency mechanisms.

---

# 70. Recoverability and Recovery

Recovery is needed when there is a failure such as:

- Transaction failure
- System crash
- Power failure
- Disk/media failure

The recovery mechanism tries to preserve atomicity and durability.

---

# 71. Failure Types

## Transaction failure

Transaction itself cannot continue.

Example:

- Constraint violation
- Arithmetic error
- Deadlock victim

## System crash

Main memory contents may be lost, while stable storage remains.

## Media failure

Disk/storage itself is damaged.

Usually needs backup plus recovery.

---

# 72. Log-Based Recovery

Instead of copying the entire database, DBMS maintains a log of changes.

Example log record:

```text
<T1, A, old=100, new=80>
```

This says T1 changed A from 100 to 80.

## Write-Ahead Logging - WAL

Basic rule:

> The relevant log record must reach stable storage before the corresponding modified data page is written to disk.

Why?

If a crash happens, the log is available for recovery.

---

# 73. UNDO and REDO

## UNDO

Reverse changes of transactions that should not survive.

Use old values.

Example:

```text
old = 100
new = 80
```

Undo means restore 100.

## REDO

Reapply changes that should survive but may not yet be present on disk.

Use new values.

Redo means write 80 again.

---

# 74. Deferred Update

Database pages are not updated with a transaction's changes before it commits.

If transaction fails before commit:

- No DB undo is needed for that transaction's data changes.

If crash happens after commit but changes are not fully written:

- REDO committed changes from the log.

This is conceptually a redo-oriented approach.

---

# 75. Immediate Update

Database pages may be written before transaction commits.

Therefore recovery may need both:

- UNDO for uncommitted transactions
- REDO for committed transactions whose updates are missing from the database pages

This is a more general approach used by many practical systems.

---

# 76. Checkpoint

Without checkpoints, recovery may need to scan a very large log.

A checkpoint gives recovery a known point from which it can start/limit work.

Conceptually:

```text
Log: ---- T1 ---- T2 ---- CHECKPOINT ---- T3 ---- crash
```

The exact checkpoint protocol depends on the DBMS.

---

# 77. Shadow Paging

Shadow paging keeps an old stable page structure and writes changes to new pages.

A page table/pointer identifies the current database version.

If transaction fails:

- Discard new pages.
- Keep the old version.

If transaction commits:

- Switch the root/current pointer to the new version.

Main advantage:

- Simple atomic switch idea.

Main disadvantage:

- Can cause fragmentation and metadata/page management overhead.

It is not usually practical to copy the whole database for every transaction.

---

# 78. Durability - How is it Achieved?

Typical ideas include:

- Write-ahead logging
- Stable storage
- Flushing/forcing important log records to durable storage
- Checkpoints
- Replication in distributed systems
- Backups for media failure

Important distinction:

- WAL helps crash recovery.
- Replication can improve availability/durability.
- Backup is needed for serious data-loss scenarios such as media destruction or accidental deletion.

---

# 79. File and Storage Organization

A database is ultimately stored in persistent storage as pages/blocks and files.

Common hierarchy:

```text
Database
  ↓
Files
  ↓
Pages / Blocks
  ↓
Records / Tuples
```

## Page / Block

A fixed-size unit of storage and I/O used by many DBMSs.

Disk I/O is usually page-oriented, so reducing unnecessary page reads is important.

---

# 80. Record Organization

## Fixed-length records

Every record has the same size.

Advantages:

- Easy addressing
- Simple layout

## Variable-length records

Records may have different sizes.

Needed for fields like:

```text
VARCHAR
TEXT
```

More flexible but requires additional metadata/offset information.

---

# 81. File Organizations

## Heap File

Records are placed wherever free space is available.

Advantages:

- Fast insert

Disadvantage:

- Searching may require scanning many pages without an index.

## Sorted File

Records are stored in sorted order by some search key.

Good for ordered/range access.

Insert may be more expensive.

## Hash File Organization

Records are placed using a hash function.

Good for equality searches.

Not as good for range queries.

---

# 82. Indexing

Index = extra data structure that helps find records faster.

Think of a book index.

Without index:

```text
Search every page
```

With index:

```text
Search index → jump near required record
```

Advantages:

- Faster reads
- Fewer page accesses for many queries

Disadvantages:

- Extra storage
- Insert/update/delete can become more expensive because indexes also need maintenance

---

# 83. Primary Index

In classical textbook terminology, a primary index is built on the ordering/primary key of an ordered data file.

The exact meaning of "primary index" differs from modern DBMS terminology such as clustered index.

## Dense Index

An index entry exists for every search-key value/record as defined by the design.

Advantages:

- Faster direct lookup

Disadvantage:

- More space

## Sparse Index

Index contains entries for only some search-key values, often one entry per data block.

Requires the underlying data to be ordered in the relevant way.

Advantage:

- Less space

---

# 84. Secondary Index

Secondary index is an index on a field that is not the ordering field of the underlying data file.

Multiple secondary indexes can usually exist.

Example:

Data is stored by `student_id`, but we frequently search by `email`.

Create an index on `email`.

---

# 85. Clustered vs Non-clustered Index

Terminology differs among DBMSs, but the common practical idea is:

## Clustered index

Table/data rows are stored in the order associated with the clustered index key.

Usually only one such physical ordering can exist for a table.

## Non-clustered index

Separate index structure points to table rows/data locations.

Multiple non-clustered indexes can exist.

### Easy example

Clustered:

```text
Data itself is organized by student_id
```

Non-clustered:

```text
Separate lookup structure:
name → row location
```

---

# 86. Multilevel Index

If an index itself becomes large, we can build another index over the index.

Conceptually:

```text
Top index
   ↓
Middle index
   ↓
Leaf/data pages
```

This reduces the amount of index that has to be scanned.

This idea leads naturally to tree-based indexing.

---

# 87. B-Tree

B-Tree is a balanced multiway search tree designed for storage systems.

Important features:

- Balanced height
- Multiple keys/children per node
- Designed to reduce disk I/O
- Search, insertion and deletion are usually logarithmic in the number of entries

---

# 88. B+ Tree

B+ tree is widely used in database indexing.

Main idea:

- Internal nodes store search keys and child pointers.
- Leaf nodes store search keys and record pointers (or records, depending on implementation).
- Leaf nodes are linked for efficient sequential/range access.

Example idea:

```text
              [30 | 60]
             /    |    \
         <30   30-59   >=60
          ↓      ↓       ↓
        leaves linked left → right
```

## Why B+ tree is useful

Point query:

```text
WHERE id = 50
```

Range query:

```text
WHERE id BETWEEN 50 AND 100
```

The linked leaves make range scans efficient.

### B-tree vs B+ tree

| B-tree | B+ tree |
|---|---|
| Records/search information can appear in internal nodes | Actual record pointers are typically at leaves |
| Leaf linking is not the defining feature | Leaves are linked in common implementations |
| Search can finish at internal node | Search usually reaches leaf |
| Range scans are less naturally organized | Excellent for range scans |

---

# 89. Hash Indexing

Hash index uses a hash function to map a key to a bucket.

Example:

```text
h(105) → bucket 5
```

Good for equality:

```sql
WHERE id = 105
```

Not good for range:

```sql
WHERE id BETWEEN 100 AND 200
```

because hash order does not preserve key order.

## Collision

Two keys may map to the same bucket.

Need collision handling such as overflow chains or other bucket management techniques.

---

# 90. B+ Tree vs Hash Index

| B+ Tree | Hash |
|---|---|
| Good for equality | Excellent for equality |
| Good for range queries | Poor for range queries |
| Maintains sorted key order | Does not preserve sorted order |
| Supports ordered traversal | Ordered traversal is not natural |

---

# 91. Index Selection

Do not blindly index every column.

Good index candidates often include columns used frequently in:

- WHERE
- JOIN
- ORDER BY
- GROUP BY

But actual benefit depends on:

- Selectivity
- Data distribution
- Query pattern
- Table size
- Write frequency

### Selectivity

A highly selective predicate returns a small fraction of rows.

Example:

```text
passport_number = 'X123'
```

Usually highly selective.

Example:

```text
gender = 'M'
```

may be much less selective in many datasets.

---

# 92. Query Processing

When a DBMS receives a query, conceptually it performs steps like:

```text
SQL query
   ↓
Parsing / validation
   ↓
Query representation
   ↓
Query optimization
   ↓
Execution plan
   ↓
Execution engine
   ↓
Storage / indexes
```

---

# 93. Query Optimization

The optimizer tries to find a low-cost execution plan.

Example:

Query:

```sql
SELECT *
FROM Employee e
JOIN Department d ON e.dept_id = d.dept_id
WHERE e.salary > 100000;
```

A good plan may filter high-salary employees before performing a large join.

Possible decisions:

- Which index to use
- Join order
- Join algorithm
- Whether to scan or seek
- Which filters should be applied early

The exact plan is chosen using DBMS-specific cost estimates.

---

# 94. Join Algorithms - Basic Idea

## Nested Loop Join

For each row from the outer relation, search the inner relation.

Simple but can be expensive.

## Hash Join

Build a hash table on one side and probe it using rows from the other side.

Good for equi-joins in suitable workloads.

## Sort-Merge Join

Sort both inputs and merge matching keys.

Useful when sorted data is already available or useful for further operations.

---

# 95. Buffer Manager

Disk is slower than main memory.

DBMS therefore keeps frequently used pages in memory buffers.

Buffer manager handles:

- Loading pages into memory
- Reusing memory frames
- Eviction decisions
- Writing dirty pages back to disk

Important concept:

```text
Page read from disk → buffer memory → used by query
```

---

# 96. Dirty Page

A page is dirty when the in-memory version has been modified but the updated version has not yet been written to stable storage.

Recovery mechanisms must make sure dirty pages can be handled safely after crashes.

---

# 97. SQL NULL

NULL means missing/unknown/not applicable depending on context.

It is not equal to:

```text
0
''
FALSE
```

Also:

```sql
NULL = NULL
```

does not evaluate to TRUE in normal SQL three-valued logic.

Use:

```sql
IS NULL
IS NOT NULL
```

Example:

```sql
SELECT *
FROM Student
WHERE phone IS NULL;
```

---

# 98. Three-Valued Logic

SQL conditions can produce:

- TRUE
- FALSE
- UNKNOWN

This is important when NULL participates in a condition.

Example:

```sql
salary > 50000
```

If salary is NULL, the result is UNKNOWN, not FALSE.

---

# 99. DELETE vs TRUNCATE vs DROP

## DELETE

- Removes selected rows.
- Can use `WHERE`.
- Usually logged row-by-row depending on DBMS.
- Transaction behavior is DBMS-specific, but it is generally transactional in modern RDBMSs.

## TRUNCATE

- Removes all rows from a table quickly.
- Usually does not allow a `WHERE` clause.
- Exact logging/rollback behavior depends on DBMS.

## DROP

- Removes the table object itself.

Simple memory trick:

```text
DELETE  → rows
TRUNCATE → all rows
DROP → table/object
```

---

# 100. WHERE vs HAVING

```text
WHERE  → row filtering
GROUP BY → grouping
HAVING → group filtering
```

Example:

```sql
SELECT dept_id, AVG(salary)
FROM Employee
WHERE salary > 30000
GROUP BY dept_id
HAVING AVG(salary) > 60000;
```

---

# 101. Primary Key vs Foreign Key

| Primary Key | Foreign Key |
|---|---|
| Identifies a row | Connects tables |
| Unique in that table | Values may repeat |
| Cannot be NULL | Can be NULL if optional |
| One PK constraint per table | Multiple FK constraints possible |

---

# 102. SQL Injection

SQL injection happens when untrusted input is combined with SQL in an unsafe way.

Bad idea:

```text
"SELECT * FROM users WHERE name = '" + input + "'"
```

Safer approach:

- Parameterized queries
- Prepared statements
- Input validation
- Least privilege

Example concept:

```text
PreparedStatement
```

The exact API depends on the language.

---

# 103. Database Security Basics

Main areas:

- Authentication = who are you?
- Authorization = what can you access?
- Auditing = what happened?
- Encryption in transit
- Encryption at rest
- Least privilege
- Secure backups

---

# 104. Transactions and Savepoint

A savepoint lets a transaction create an intermediate rollback point.

Example:

```sql
SAVEPOINT s1;
```

Later:

```sql
ROLLBACK TO s1;
```

This does not necessarily end the entire transaction.

---

# 105. COMMIT vs ROLLBACK

## COMMIT

Makes transaction changes permanent according to the DBMS's durability protocol.

## ROLLBACK

Undo/rejects uncommitted changes from the transaction, subject to DBMS behavior.

---

# 106. ACID Example - Bank Transfer

Initial:

```text
A = 1000
B = 500
```

Transfer 200 from A to B.

Transaction:

```text
A = 800
B = 700
```

If the system crashes after debiting A but before crediting B, atomicity + recovery should prevent the final state from becoming:

```text
A = 800
B = 500
```

The DBMS should recover to either the old valid state or the new valid state.

---

# 107. Distributed Database

A distributed database stores data across multiple machines/sites but is managed so applications can interact with it as a coordinated database system.

Reasons:

- Scalability
- Availability
- Geographic locality
- Fault tolerance

Challenges:

- Network failures
- Distributed transactions
- Replication consistency
- Data placement
- Clock/timing issues
- Monitoring and operational complexity

---

# 108. Replication

Replication = keeping copies of data at multiple nodes.

## Primary-Replica idea

```text
Primary
  ↓ writes
Replicas
```

Replicas may serve reads depending on the system.

Advantages:

- Better read scalability
- Higher availability

Trade-offs:

- Replication lag
- More storage
- Failover complexity

## Synchronous vs Asynchronous

### Synchronous

Write is acknowledged after required replicas confirm it according to the system's protocol.

Can improve consistency/durability, but may increase latency.

### Asynchronous

Primary can acknowledge earlier.

Lower latency, but replicas may lag.

---

# 109. Partitioning

Partitioning divides a large relation into smaller logical pieces called partitions.

## Horizontal Partitioning

Split rows.

Example:

```text
Users 1-50000 → Partition A
Users 50001-100000 → Partition B
```

## Vertical Partitioning

Split columns.

Example:

```text
P1(id, name, phone)
P2(id, address, salary)
```

The common key allows reconstruction when necessary.

---

# 110. Sharding

Sharding = distributing partitions of data across multiple database servers.

Example:

```text
Shard 1 → users 1-1M
Shard 2 → users 1M-2M
Shard 3 → users 2M-3M
```

A routing layer determines where a key belongs.

## Shard key

The attribute used to decide data placement.

A good shard key should avoid severe hotspots and provide a useful distribution.

### Benefits

- Horizontal scale
- More storage capacity
- More write/read capacity in suitable workloads

### Problems

- Resharding complexity
- Cross-shard queries
- Cross-shard transactions
- Hot partitions
- Scatter-gather queries

---

# 111. Sharding vs Partitioning

Partitioning is the general idea of splitting a table into pieces.

Sharding usually means those pieces are distributed across multiple machines.

So:

```text
Partitioning = split data
Sharding = split + distribute across servers
```

---

# 112. CAP Theorem

CAP refers to:

- Consistency
- Availability
- Partition tolerance

In a distributed system, when a network partition occurs, a system cannot simultaneously guarantee both strong consistency and availability for every operation under the CAP model.

## Consistency

Every read sees the latest committed write or an equivalent strong-consistency result according to the model, often described as linearizability.

## Availability

Every request to a non-failing node receives a non-error response within a finite time, according to the CAP definition.

## Partition Tolerance

The system continues operating despite communication failures that split nodes into groups.

### CP

During partition, prioritize consistency and may reject/delay some requests.

### AP

During partition, continue serving requests and allow temporary inconsistency.

### CA

The CA combination is meaningful only when partition failure is not present in the model/environment. In a real distributed network, partitions can occur, so practical distributed systems have to consider P.

---

# 113. NoSQL

NoSQL is commonly expanded as "Not Only SQL".

It refers to non-relational database systems designed for different data and scaling patterns.

Major families:

1. Key-value
2. Document
3. Wide-column
4. Graph

Important correction:

- NoSQL does not automatically mean "no ACID".
- Modern NoSQL systems can provide transactions and strong consistency features.
- "Eventual consistency" is common in some distributed NoSQL systems, not a universal rule for all NoSQL databases.

---

# 114. Why NoSQL Became Popular

Common reasons:

- Large-scale web applications
- Huge amounts of semi-structured data
- Distributed systems
- Flexible schemas
- Horizontal scaling needs
- High write/read throughput

---

# 115. Key-Value Store

Data is stored as:

```text
Key → Value
```

Example:

```text
session:123 → {...}
```

Good use cases:

- Caching
- Sessions
- Shopping carts
- Simple lookups

Examples:

- Redis
- Amazon DynamoDB

---

# 116. Document Database

Data is stored as documents, often JSON/BSON-like.

Example:

```json
{
  "id": 1,
  "name": "Kalyan",
  "skills": ["C++", "DBMS", "React"]
}
```

Good for:

- Content systems
- Product catalogs
- Applications with changing document shape

Examples:

- MongoDB
- Couchbase

---

# 117. Wide-Column Database

Stores data in column families / wide rows.

Designed for large-scale distributed workloads.

Examples:

- Apache Cassandra
- HBase

Good for workloads with huge data and predictable access patterns.

---

# 118. Graph Database

Data is stored as:

- Nodes
- Edges
- Properties

Example:

```text
(Kalyan) --follows--> (Ravi)
```

Good for:

- Social networks
- Recommendation systems
- Fraud relationships
- Knowledge graphs

Example:

- Neo4j

---

# 119. SQL vs NoSQL

| SQL / Relational | NoSQL |
|---|---|
| Tables | Documents / key-value / graph / wide-column |
| Usually stronger predefined schema | Often flexible schema |
| Rich joins | Usually application/data-model-specific relationships |
| Strong relational model | Different data models |
| Often scales vertically and can also scale horizontally | Horizontal scaling is common in many systems |
| ACID transactions are central | Transaction/consistency model depends on the DB |

Use case matters more than saying one is always better.

---

# 120. Scaling

## Vertical Scaling / Scale Up

Increase power of one server.

```text
More CPU
More RAM
More SSD
```

Advantages:

- Simple
- Little application change

Disadvantages:

- Hardware limit
- Expensive at the high end
- Single machine may remain a major failure boundary

## Horizontal Scaling / Scale Out

Add more servers.

```text
Server 1
Server 2
Server 3
```

Advantages:

- Large-scale capacity
- Can improve availability

Disadvantages:

- Distributed-system complexity
- Need load balancing/partitioning/replication
- More operational complexity

---

# 121. Load Balancing

Load balancing distributes incoming requests across multiple servers.

Example:

```text
Client
  ↓
Load Balancer
  ├── Server 1
  ├── Server 2
  └── Server 3
```

Benefits:

- Better utilization
- More capacity
- Failover support in suitable designs

Common strategies:

- Round robin
- Least connections
- Weighted routing

---

# 122. Clustering - Important Terminology

The word "clustering" is overloaded.

In practical systems, it can mean:

1. A cluster of database servers working together.
2. Clustered storage/indexing where rows are physically organized around a key.
3. Related rows/data being stored close together.

So always clarify the context.

---

# 123. OLTP vs OLAP

## OLTP

Online Transaction Processing.

Focus:

- Many short transactions
- Inserts/updates
- Fast point lookups
- Strong consistency requirements

Examples:

- Banking
- Orders
- Payments

## OLAP

Online Analytical Processing.

Focus:

- Large analytical queries
- Aggregation
- Reporting
- Trends

Examples:

- Sales dashboards
- Business intelligence

---

# 124. Primary Database vs Data Warehouse

Operational database:

- Supports day-to-day application transactions.

Data warehouse:

- Stores integrated historical data for analytics.

Typical warehouse workloads are more read-heavy and analytical.

---

# 125. Star Schema

Common warehouse design.

```text
        Dimension
            |
Dimension -- Fact -- Dimension
            |
        Dimension
```

Fact table contains measurements and foreign keys.

Dimension tables describe the business entities.

Example:

```text
SalesFact
(date_id, product_id, store_id, amount)
```

Dimensions:

```text
Date
Product
Store
```

---

# 126. OLTP vs OLAP Quick Difference

| OLTP | OLAP |
|---|---|
| Transactional | Analytical |
| Many small queries | Fewer large queries |
| Frequent writes | Heavy reads/aggregations |
| Current operational data | Historical/analytical data |
| Normalized designs are common | Denormalized dimensional designs are common |

---

# 127. Common Interview Differences

## DBMS vs RDBMS

DBMS is the general database management concept.

RDBMS specifically follows the relational/table-based model.

## Schema vs Instance

```text
Schema = structure
Instance = current data
```

## Primary Key vs Candidate Key

```text
Candidate key = possible minimal unique identifier
Primary key = candidate key selected as main identifier
```

## Super Key vs Candidate Key

```text
Super key = unique, may contain extra attributes
Candidate key = minimal super key
```

## Primary Index vs Primary Key

These are not the same thing.

- Primary key = logical constraint/identifier.
- Primary index = indexing concept, especially in classical file organization.

## Clustered Index vs Primary Index

Not universally synonymous.

- Classical textbook primary index is tied to the ordering key.
- Modern clustered index means physical row ordering/storage is associated with the indexed key.

## DELETE vs TRUNCATE vs DROP

```text
DELETE  → removes rows
TRUNCATE → removes all rows from table
DROP → removes table/object
```

## WHERE vs HAVING

```text
WHERE → before grouping
HAVING → after grouping
```

## UNION vs UNION ALL

```text
UNION     → removes duplicates
UNION ALL → keeps duplicates
```

## 2NF vs 3NF

```text
2NF → removes partial dependency
3NF → removes transitive dependency / satisfies formal 3NF condition
```

## 3NF vs BCNF

```text
BCNF is stricter.
3NF can allow some dependencies where the determinant is not a superkey if the RHS is prime.
BCNF does not allow that.
```

## B+ Tree vs Hash Index

```text
B+ Tree → equality + range
Hash    → equality is the main strength
```

## Partitioning vs Sharding

```text
Partitioning → split a table/data
Sharding → distribute partitions across servers
```

---

# 128. Important DBMS Concepts to Remember Together

A useful mental chain is:

```text
ER Model
   ↓
Relational Model
   ↓
Functional Dependencies
   ↓
Normalization
   ↓
Tables + Constraints
   ↓
SQL
   ↓
Indexes
   ↓
Query Optimization
   ↓
Transactions
   ↓
Concurrency Control
   ↓
Recovery
   ↓
Replication / Sharding / Distributed DB
```

---

# 129. A Simple End-to-End Example

Suppose I build a college management system.

## Step 1 - Entities

```text
Student
Department
Course
Teacher
```

## Step 2 - Relationships

```text
Student → belongs to → Department
Student → enrolls in → Course
Teacher → teaches → Course
```

## Step 3 - Convert to tables

```text
Student(student_id, name, dept_id)
Department(dept_id, dept_name)
Course(course_id, course_name, teacher_id)
Enrollment(student_id, course_id, grade)
Teacher(teacher_id, teacher_name)
```

## Step 4 - Keys

```text
Student.student_id = PK
Department.dept_id = PK
Course.course_id = PK
Teacher.teacher_id = PK
Enrollment(student_id, course_id) = composite PK
```

## Step 5 - Foreign keys

```text
Student.dept_id → Department.dept_id
Course.teacher_id → Teacher.teacher_id
Enrollment.student_id → Student.student_id
Enrollment.course_id → Course.course_id
```

## Step 6 - Normalize

Keep student, department, course and teacher information separate to reduce duplication.

## Step 7 - Add indexes

Possible indexes:

```text
Student(dept_id)
Course(teacher_id)
Enrollment(course_id)
```

Actual indexes depend on query workload.

## Step 8 - Transaction

Suppose a student enrolls in a course.

A transaction may need to:

1. Validate course exists.
2. Validate seat availability.
3. Insert enrollment.
4. Update seat count.
5. Commit.

If one important step fails, the transaction should not leave the system in an invalid partial state.

---

# 130. Final DBMS Revision Sheet

## Basics

- Database = organized collection of data.
- DBMS = software that manages the database.
- Schema = structure.
- Instance = current data.
- Physical level = storage.
- Logical level = database structure.
- External level = user views.
- Physical data independence = physical storage can change without changing logical schema.
- Logical data independence = logical schema can change with limited effect on external views.

## ER Model

- Entity = real-world object.
- Entity set = collection of similar entities.
- Attribute = property.
- Relationship = association.
- Strong entity = has own key.
- Weak entity = depends on owner.
- Cardinality = 1:1, 1:N, M:N.
- Participation = total/partial.
- Specialization = top-down.
- Generalization = bottom-up.
- Aggregation = relationship treated as higher-level object.

## Relational Model

- Tuple = row.
- Attribute = column.
- Degree = number of columns.
- Cardinality = number of rows.
- Super key = unique, not necessarily minimal.
- Candidate key = minimal super key.
- Primary key = selected candidate key.
- Alternate key = unselected candidate key.
- Foreign key = reference to a key in another table.
- Composite key = multiple attributes.
- Surrogate key = artificial identifier.

## Constraints

- Domain
- Entity integrity
- Referential integrity
- NOT NULL
- UNIQUE
- CHECK
- DEFAULT

## SQL

- DDL = CREATE, ALTER, DROP, TRUNCATE
- DML = INSERT, UPDATE, DELETE
- DQL = SELECT (classification varies)
- DCL = GRANT, REVOKE
- TCL = COMMIT, ROLLBACK, SAVEPOINT
- WHERE = row filter
- GROUP BY = groups rows
- HAVING = filters groups
- ORDER BY = sort
- JOIN = combine related rows

## Functional Dependency

```text
X → Y
```

X determines Y.

- Trivial FD
- Non-trivial FD
- Armstrong axioms
- Attribute closure
- Candidate key finding

## Normalization

```text
1NF → atomic values
2NF → remove partial dependency
3NF → remove transitive dependency / satisfy formal 3NF
BCNF → every determinant of a non-trivial FD is a superkey
4NF → handle non-trivial MVDs
5NF → handle join dependencies
```

Also remember:

- Lossless decomposition
- Dependency preservation

## Transactions

ACID:

```text
A → Atomicity
C → Consistency
I → Isolation
D → Durability
```

Transaction states:

```text
Active
Partially committed
Committed
Failed
Aborted
Terminated
```

## Concurrency

- Serial schedule
- Non-serial schedule
- Conflict serializability
- View serializability
- Precedence graph
- Shared lock
- Exclusive lock
- 2PL
- Strict 2PL
- Deadlock
- Timestamp ordering
- Optimistic concurrency control
- MVCC

## Concurrency anomalies

- Lost update
- Dirty read
- Non-repeatable read
- Phantom read
- Incorrect summary

## Recovery

- WAL
- UNDO
- REDO
- Deferred update
- Immediate update
- Checkpoint
- Shadow paging
- Backup

## Indexing

- Dense index
- Sparse index
- Primary index
- Secondary index
- Clustered index
- Non-clustered index
- B-tree
- B+ tree
- Hash index

## Distributed DB

- Replication
- Partitioning
- Sharding
- Load balancing
- CAP theorem
- Distributed transactions

## NoSQL

- Key-value
- Document
- Wide-column
- Graph

---

# 131. One-Line Interview Definitions

### What is DBMS?

DBMS is software used to store, retrieve, update, secure and manage data in a database.

### What is normalization?

Normalization is the process of organizing relations using dependencies to reduce unnecessary redundancy and anomalies.

### What is a primary key?

A primary key is the selected candidate key used to uniquely identify rows in a table.

### What is a foreign key?

A foreign key is an attribute or set of attributes that references a key in another table and helps maintain referential integrity.

### What is a transaction?

A transaction is a logical unit of database work that should satisfy the required atomicity, consistency, isolation and durability guarantees.

### What is indexing?

Indexing adds a search structure so the DBMS can find matching rows with fewer page accesses.

### What is a B+ tree?

A B+ tree is a balanced multiway index structure whose leaves are commonly linked, making both point lookup and range scans efficient.

### What is sharding?

Sharding distributes partitions of data across multiple database servers.

### What is CAP theorem?

CAP says that during a network partition, a distributed system cannot simultaneously provide both strong consistency and availability for every operation under the CAP model.

---

# 132. Final Memory Map

If I have very little time before an interview, I revise in this order:

```text
1. DBMS basics + 3-schema architecture
2. Keys + constraints
3. ER model + ER to relational conversion
4. Relational algebra
5. SQL + joins + subqueries + group by
6. Functional dependency + closure
7. 1NF, 2NF, 3NF, BCNF
8. Transactions + ACID
9. Serializability + locks + 2PL
10. Deadlocks + isolation levels
11. Recovery + WAL + checkpoint
12. Indexing + B+ tree + hashing
13. Query optimization basics
14. NoSQL
15. Replication + partitioning + sharding
16. CAP theorem
```

The main thing is not to memorize isolated definitions. I should connect the concepts:

```text
Good schema
→ fewer anomalies
→ useful indexes
→ faster queries
→ transactions keep changes correct
→ concurrency control keeps concurrent work safe
→ recovery handles crashes
→ replication/sharding handle scale and availability
```
