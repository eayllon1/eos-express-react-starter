#include <eosiolib/eosio.hpp>

using namespace eosio;
using std::string;

class [[eosio::contract("addressbook")]] addressbook : public eosio::contract {
  public:

  private:
    struct person {
      name key;
      string first_name;
      string last_name;
      string street;
      string city;
      string state;
      uint64_t primary_key() const {
        return key.value;
      };
    }

    typedef eosio::multi_index<"people"_n, person> address_index;

};
