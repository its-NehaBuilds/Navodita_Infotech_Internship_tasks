#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>

using namespace std;

class Product {
public:
    int id;
    string name;
    int quantity;
    double price;

    Product(int i, string n, int q, double p) {
        id = i;
        name = n;
        quantity = q;
        price = p;
    }
};

class Supplier {
public:
    int supplierId;
    string supplierName;
    string contact;

    Supplier(int id, string name, string con) {
        supplierId = id;
        supplierName = name;
        contact = con;
    }
};

vector<Product> products;
vector<Supplier> suppliers;

void addProduct() {
    int id, quantity;
    string name;
    double price;

    cout << "\nEnter Product ID: ";
    cin >> id;

    cin.ignore();

    cout << "Enter Product Name: ";
    getline(cin, name);

    cout << "Enter Quantity: ";
    cin >> quantity;

    cout << "Enter Price: ";
    cin >> price;

    products.push_back(Product(id, name, quantity, price));

    cout << "\nProduct Added Successfully!\n";
}

void viewProducts() {
    if(products.empty()) {
        cout << "\nNo Products Available!\n";
        return;
    }

    cout << "\n---------------- PRODUCT LIST ----------------\n";

    cout << left
         << setw(10) << "ID"
         << setw(25) << "Name"
         << setw(15) << "Quantity"
         << setw(15) << "Price"
         << endl;

    for(auto &p : products) {
        cout << left
             << setw(10) << p.id
             << setw(25) << p.name
             << setw(15) << p.quantity
             << setw(15) << p.price
             << endl;
    }
}

void searchProduct() {
    int id;

    cout << "\nEnter Product ID to Search: ";
    cin >> id;

    for(auto &p : products) {
        if(p.id == id) {
            cout << "\nProduct Found!\n";
            cout << "Name: " << p.name << endl;
            cout << "Quantity: " << p.quantity << endl;
            cout << "Price: " << p.price << endl;
            return;
        }
    }

    cout << "\nProduct Not Found!\n";
}

void updateQuantity() {
    int id;

    cout << "\nEnter Product ID: ";
    cin >> id;

    for(auto &p : products) {
        if(p.id == id) {
            cout << "Current Quantity: " << p.quantity << endl;

            cout << "Enter New Quantity: ";
            cin >> p.quantity;

            cout << "\nQuantity Updated Successfully!\n";
            return;
        }
    }

    cout << "\nProduct Not Found!\n";
}

void deleteProduct() {
    int id;

    cout << "\nEnter Product ID to Delete: ";
    cin >> id;

    for(int i = 0; i < products.size(); i++) {
        if(products[i].id == id) {
            products.erase(products.begin() + i);

            cout << "\nProduct Deleted Successfully!\n";
            return;
        }
    }

    cout << "\nProduct Not Found!\n";
}

void addSupplier() {
    int id;
    string name;
    string contact;

    cout << "\nEnter Supplier ID: ";
    cin >> id;

    cin.ignore();

    cout << "Enter Supplier Name: ";
    getline(cin, name);

    cout << "Enter Contact Number: ";
    getline(cin, contact);

    suppliers.push_back(Supplier(id, name, contact));

    cout << "\nSupplier Added Successfully!\n";
}

void viewSuppliers() {
    if(suppliers.empty()) {
        cout << "\nNo Suppliers Available!\n";
        return;
    }

    cout << "\n---------------- SUPPLIER LIST ----------------\n";

    for(auto &s : suppliers) {
        cout << "\nSupplier ID : " << s.supplierId;
        cout << "\nName        : " << s.supplierName;
        cout << "\nContact     : " << s.contact << endl;
    }
}

void generateReport() {
    cout << "\n=========== INVENTORY REPORT ===========\n";

    cout << "Total Products: " << products.size() << endl;

    double totalValue = 0;

    for(auto &p : products) {
        totalValue += p.quantity * p.price;
    }

    cout << "Total Inventory Value: Rs. "
         << fixed << setprecision(2)
         << totalValue << endl;

    cout << "\nLow Stock Products (Quantity < 5)\n";

    bool found = false;

    for(auto &p : products) {
        if(p.quantity < 5) {
            cout << p.name
                 << " (Qty: "
                 << p.quantity
                 << ")\n";

            found = true;
        }
    }

    if(!found) {
        cout << "No Low Stock Products.\n";
    }
}

void saveProducts() {
    ofstream file("products.txt");

    for(auto &p : products) {
        file << p.id << ","
             << p.name << ","
             << p.quantity << ","
             << p.price << endl;
    }

    file.close();

    cout << "\nData Saved Successfully!\n";
}

int main() {

    int choice;

    do {

        cout << "\n=========================================\n";
        cout << "      INVENTORY MANAGEMENT SYSTEM\n";
        cout << "=========================================\n";

        cout << "1. Add Product\n";
        cout << "2. View Products\n";
        cout << "3. Search Product\n";
        cout << "4. Update Quantity\n";
        cout << "5. Delete Product\n";
        cout << "6. Add Supplier\n";
        cout << "7. View Suppliers\n";
        cout << "8. Generate Report\n";
        cout << "9. Save Data\n";
        cout << "10. Exit\n";

        cout << "\nEnter Choice: ";
        cin >> choice;

        switch(choice) {

            case 1:
                addProduct();
                break;

            case 2:
                viewProducts();
                break;

            case 3:
                searchProduct();
                break;

            case 4:
                updateQuantity();
                break;

            case 5:
                deleteProduct();
                break;

            case 6:
                addSupplier();
                break;

            case 7:
                viewSuppliers();
                break;

            case 8:
                generateReport();
                break;

            case 9:
                saveProducts();
                break;

            case 10:
                cout << "\nThank You!\n";
                break;

            default:
                cout << "\nInvalid Choice!\n";
        }

    } while(choice != 10);

    return 0;
}

