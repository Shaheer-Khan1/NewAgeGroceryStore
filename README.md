# New Age Grocery Store

## Project Overview

The "New Age Grocery Store" is an object-oriented software system designed to enhance the customer shopping experience in a large grocery store chain, transitioning from manual to automated processes. The system is implemented in C++ and provides a range of features for different types of users, including customers, store managers, and system admins.

## Features

### 1. User Registration
- **Customer Registration**: Customers can register with a valid 13-digit CNIC and a secure password (minimum 9 characters, including one uppercase letter and one numeric digit). The system ensures unique accounts and stores customer details such as gender, phone number, and address.
- **Manager Registration**: Managers can only be registered by the admin and are assigned to specific stores based on location.
- **Admin Registration**: Admins are predefined and can manage the overall system.

### 2. User Login
- **Admin Login**: Admins can log in using predefined credentials and manage stores, users, and the product catalog.
- **Manager Login**: Managers can log in to manage the inventory of their assigned store.
- **Customer Login**: Customers can log in to shop online, view their cart, and manage their account.

### 3. Home Screen & Menus
- Different home screens are presented based on user roles (Admin, Manager, Customer) with relevant menus for each user type.

### 4. Store & User Management (Admin)
- **Store Management**: Admins can manage records of all stores across the country.
- **User Management**: Admins can add, remove, or update manager accounts and manage customer accounts, including removing spam accounts.

### 5. Product Catalog Management (Admin)
- **Catalog Management**: Admins manage the product catalog, including adding, removing, and updating products across categories like food (perishable/non-perishable), personal hygiene, and household cleaning. All changes are reflected in the catalog file.

### 6. Inventory Management (Manager)
- **Inventory Management**: Managers manage the store’s inventory, adding, removing, and updating items. Inventory changes are saved in real-time, and managers can also view and search inventory in other stores.

### 7. Online Shopping (Customer)
- **Shopping Cart**: Customers can browse the product catalog, add items to their cart, and view the total cost in real-time.
- **Checkout & Payment**: Customers can choose from various payment methods like Cash on Delivery, debit/credit cards, Easypaisa, or JazzCash. The system updates inventory upon successful payment.
- **Feedback**: Customers can provide feedback or rate the store during checkout.

### 8. Payment Processing
- Supports multiple payment methods with specific charges based on the customer's location relative to the store.

### 9. Store Checkout Simulation (Admin)
- **Simulation**: A simulator allows admins to test different store checkout scenarios, including customer queues, cashier performance, and overall checkout efficiency.

## Files & Directories
- **main.cpp**: The main entry point for the program.
- **/include**: Contains header files for classes.
- **/src**: Contains the implementation files.
- **/data**: Stores data files such as user details, inventory, and product catalog.
- **README.md**: Project overview and instructions (this file).
- **self-evaluation.txt**: Self-evaluation of the project.

## How to Run
1. Clone the repository.
2. Compile the project using a C++ compiler.
3. Run the executable.
4. Follow the on-screen instructions to navigate through the system.
