CREATE TABLE premia(
    id varchar(20) PRIMARY KEY,
    premia NUMERIC
);

CREATE TABLE dzial(
    id INTEGER PRIMARY KEY,
    nazwa varchar(20),
    siedziba varchar(20)
);

CREATE TABLE pracownicy(
    id VARCHAR(6) PRIMARY KEY,
    nazwisko varchar(20),
    imie varchar(20),
    stanowisko varchar(20),
    data_zatr varchar(23),
    placa NUMERIC,
    premia NUMERIC,
    id_dzial INTEGER, 
    FOREIGN KEY(stanowisko) REFERENCES premia(id), 
    FOREIGN KEY(id_dzial) REFERENCES dzial(id) 
);
