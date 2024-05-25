CREATE TABLE IF NOT EXISTS customers (
    id int PRIMARY KEY GENERATED ALWAYS AS IDENTITY,
    name VARCHAR(255) NOT NULL,
    email VARCHAR(255) UNIQUE NOT NULL
);

CREATE TABLE IF NOT EXISTS products (
    id int PRIMARY KEY GENERATED ALWAYS AS IDENTITY,
    name VARCHAR(255) NOT NULL,
    price DECIMAL NOT NULL
);

CREATE TABLE IF NOT EXISTS orders (
    id int PRIMARY KEY GENERATED ALWAYS AS IDENTITY,
    customer_id int NOT NULL REFERENCES customers(id),
    product_id int NOT NULL REFERENCES products(id),
    CONSTRAINT unique_customer_product UNIQUE(customer_id, product_id)
);

INSERT INTO customers (name, email)
VALUES ('Caleb', 'calcur@email.com');

INSERT INTO products (name, price)
VALUES
('Standard Product', 59),
('Premium Product', 199);

INSERT INTO orders (customer_id, product_id) VALUES (1, 1);