# 🗳️ Coalition Race Simulation

Welcome to the **Coalition Race**, a C++ simulation that models the strategic formation of coalitions in a fictional democracy named **SPLand**. This project focuse on object-oriented design, dynamic memory handling, and rule-based simulation in modern C++.

---

## 📌 Objective

Simulate agents from different political parties offering collaborations to reach a coalition of **at least 61 mandates**. Each agent follows a **selection strategy** to make offers, and each party has a **join strategy** to decide which coalition to join.

---

## 🧠 Simulation Overview

- **Graph**: Represents parties as vertices and agreements as edges (weighted).
- **Agents**: Start in selected parties and make offers using a selection policy.
- **Parties**: Collect offers for 3 turns, then join a coalition using their join policy.

### 🔁 Simulation Loop

Each iteration:
1. Parties update their state and possibly join a coalition.
2. Agents make new offers based on available neighbors and strategy.
3. Simulation ends if a coalition reaches 61 mandates or all parties are joined.

---

## 🧩 Components

| Component               | Description                                           |
|------------------------|-------------------------------------------------------|
| `main.cpp`             | Loads config, runs simulation loop, writes output     |
| `Simulation.cpp`       | Manages graph, agents, party state, termination logic |
| `Agent.cpp`            | Implements agent behavior, cloning, and offers        |
| `Party.cpp`            | Handles offer collection, joining logic, and timing   |
| `Graph.cpp`            | Manages the graph and neighbors                       |
| `Offer.cpp`            | Tracks offers made to parties                         |
| `Parser.cpp`           | Parses JSON input/output                              |
| `SelectionPolicy.*`    | Abstract + `MandatesSelectionPolicy`, `EdgeWeightSelectionPolicy` |
| `JoinPolicy.*`         | Abstract + `MandatesJoinPolicy`, `LastOfferJoinPolicy`|

### 🧠 Selection Policies
- **MandatesSelectionPolicy**: Picks neighbor with most mandates
- **EdgeWeightSelectionPolicy**: Picks neighbor with highest edge weight

### 🧠 Join Policies
- **MandatesJoinPolicy**: Joins coalition with most mandates (tie → earliest)
- **LastOfferJoinPolicy**: Joins the last coalition that made an offer

---

## ✅ Termination Conditions

The simulation stops when:
- A coalition gathers **≥ 61 mandates**, or
- **All parties have joined** coalitions

---

