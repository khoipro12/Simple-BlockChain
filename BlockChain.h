#pragma once
#include <string>
#include "function.h"
#include "sha256.h"
#include <vector>
#include <iostream>
#include "json.h"

class Block {
private:
	std::string Hash;
	std::string data;
	std::string prev_hash;
	json x;
	int nonce = 0;
public:
	Block(std::string data) {

		this->data = data;
		this->Hash = hash(data);
	}
	Block(json& x) {
		std::string temp = "";
		for (auto& i : x.get_vector()) {
			temp += "from:" + i["from"] + " " + "to:" + i["to"] + "\n";
		}
		this->data = temp;
		this->Hash = hash(temp);
		this->x = x;
	}
	void show() {
		std::cout << "Data: ";
		std::cout << data << std::endl;
		std::cout << "Previous Hash: " << prev_hash << std::endl;
		std::cout << "Hash: " << Hash << std::endl;
		std::cout << "Nonce: " << nonce << std::endl;
		std::cout << std::endl;

	}
	void add_PreviousHash(std::string hash) {
		prev_hash = hash;
	}
	std::string get_hash() {
		return Hash;
	}
	json get_json() {
		return x;
	}
	void up_nonce() {
		nonce += 1;
	}
	void change_hash(std::string data) {
		this->Hash = hash(data + std::to_string(nonce));
	}
	std::string get_data() {
		return data;
	}
};

class BlockChain {
private:
	std::vector<Block> x;
public:
	BlockChain() {
		Block geneisblock = Block("Geneis Block");
		x.push_back(geneisblock);
	};
	void add_block(json data) {
		Block block = Block(data);
		block.add_PreviousHash(x[x.size() - 1].get_hash());
		while (startwith(block.get_hash(), "000") == false) {
			block.up_nonce();
			block.change_hash(block.get_data());
		}
		x.push_back(block);

	}
	int get_balance(std::string name) {
		int blance = 0;
		for (auto& i : x) {
			for (auto& j : i.get_json().get_vector()) {
				if (j["from"] == name) {
					blance = blance - std::stoi(j["amount"]);
				}
				if (j["to"] == name) {
					blance = blance + std::stoi(j["amount"]);
				}
			}
		}
		return blance;
	}
	void print() {
		for (int i = 0; i < x.size(); i++) {
			x[i].show();
		}
	}
};