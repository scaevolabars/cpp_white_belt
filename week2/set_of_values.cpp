//
// Created by serge on 11/7/2021.
//

set<string> BuildMapValuesSet(const map<int, string>& m) {
    set<string> values;
    for (const auto& item : m) {
        values.insert(item.second);
    }
    return values;
}