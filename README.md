# Insura CRM

Customer Relationship Manager developed for the Master in AI Engineering by ProfessionAI.

## Run

To run this project, you need to compile it into an executable.

```bash
g++ -o insura_crm.exe -Iinclude $(find src -name "*.cpp")
./insura_crm.exe
```

You can also run it through Makefile.

```bash
make             # compile and run
make run         # run only (error if exec not found)
make compile     # compile only
make clean       # delete the executable
make test        # compile and run test, cleanup after
```

## Stack

| Layer | Choice |
| ----- | ------ |
| Code  | C++    |
| Data  | JSON   |
