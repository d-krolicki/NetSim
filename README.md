# NetSim

To jest repozytorium używane do pracy przy projekcie NetSim z przedmiotu Zaawansowane Programowanie Obiektowe.

[Link do UML-a](https://www.plantuml.com/plantuml/uml/ZLHVRvim47yEd-BKXnQq9NsFQDHeIIgaAMGBUzXJwy0biGesiqqhcgMVVGS48fTCAaAoVNV-_V4Vtsl3b2corBc1A9o53hN3qrVrx-W37xw5oqNmyEldD0h29KpgiEFiUOA0MMvAo33ReD9DoFUtXOWDbs8oWPYhECKEQxwSWTp-5p9dyJFR8LojZLJKkOA3umouCAYsB4O8Laq1fUFddASLMPSbjeCp0Fg-m85jj54iDaV82xrtJ_EkhpqOmulaIR-miU9M1HifKpZyAL2Lnmk5chzXNLTr7asPOwyuGxENoH5kEObZPAQyRNFlFHEkvmoESD7eZmABJvcKUQteDEr2nGxD8uai6i5jSSSHMIv8pU32MlyT3crbf1b5aVMHVB-ALzQv58tcmI9OXDHyhniYwKyQZMpuCU4K6lLaGaHnohIscBgLiABkHrolPhE0oGfnsKviWbfn1-nwrcYUOeR213Cxt1so9YppPkllxDFN3kgQQbTuudfZw33Fkq3vznQxDk7GVmFdQzIxBbMQZCscqHIYtwlvccupXO84Z8It1BTSSFdAH0cla2kvKopZ2ARCgv4s9RWY7m5BETCW63nnOPuynqYIkKS5XtQHpc9z7zpegrGnNNsFK7Z63N-XO_fHQmlYzD-2LRWEgcSWM3wqBy4zYgJ8qdy0)

## Podział funkcjonalności pomiędzy pliki nagłówkowe:
- **factory.hpp:**
  szablon klasy NodeCollection,
  klasa Factory,
  funkcje do zapisu i odczytu struktury fabryki z pliku
- **helpers.hpp:** pomocnicze obiekty i funkcje globalne (np. generator liczb losowych)
- **nodes.hpp:** klasy ujęte na diagramie UML w pakiecie Nodes
  typ wyliczeniowy ReceiverType
  klasy IPackageReceiver, Storehouse, ReceiverPreferences, PackageSender, Ramp, Worker
- **package.hpp:** klasa Package
- **reports.hpp:**
  klasy SpecificTurnsReportNotifier, IntervalReportNotifier,
  funkcje generate_structure_report(), generate_simulation_turn_report()
- **simulation.hpp:** funkcja simulate()
- **storage_types.hpp:**
  klasy IPackageStockpile, IPackageQueue, PackageQueue,
  typ wyliczeniowy PackageQueueType
- **types.hpp:** aliasy
