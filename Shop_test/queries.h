#ifndef QUERIES_H
#define QUERIES_H

#define CREATE_GENDERS "CREATE TABLE Genders(\
id INTEGER PRIMARY KEY AUTOINCREMENT,\
gen_name VARCHAR(255)NOT NULL UNIQUE\
)"
#define CREATE_CATEGORIES "CREATE TABLE categories(\
id INTEGER PRIMARY KEY AUTOINCREMENT,\
c_name VARCHAR(255)NOT NULL UNIQUE\
);"
#define CREATE_DRESS_KINDS "CREATE TABLE Dress_kinds(\
d_id INTEGER PRIMARY key AUTOINCREMENT,\
d_name varchar(255) NOT NULL UNIQUE,\
d_category ingeter,\
d_gender integer,\
foreign key (d_gender) references Genders(id),\
FOREIGN key (d_category) REFERENCES categories(id)\
)"
#define CREATE_UNITS "CREATE TABLE units(\
u_id INTEGER PRIMARY KEY AUTOINCREMENT,\
u_name VARCHAR(255)NOT NULL UNIQUE\
);"
#define CREATE_GOODS "CREATE TABLE goods(\
g_id INTEGER PRIMARY KEY AUTOINCREMENT,\
g_name VARCHAR(255)NOT NULL UNIQUE,\
g_kind INTEGER,\
g_unit INTEGER,\
g_price REAL,\
FOREIGN KEY (g_kind) REFERENCES Dress_kinds(d_id),\
FOREIGN KEY (g_unit) REFERENCES units(u_id)\
);"
#define CREATE_POSITIONS "CREATE TABLE POSITIONS(\
p_id INTEGER PRIMARY KEY AUTOINCREMENT,\
p_goods INTEGER,\
p_count INTEGER,\
p_weight INTEGER\
);"

#endif // QUERIES_H
