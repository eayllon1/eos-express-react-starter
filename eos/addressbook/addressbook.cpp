#include <eosiolib/eosio.hpp>

using namespace eosio;
using std::string;

class [[eosio::contract("addressbook")]] addressbook : public eosio::contract {
  public:
    using contract::contract;

    addressbook(name receiver, name code, datastream<const char*> ds):contract(receiver, code, ds) {}

    [[eosio::action]]
    void upsert(
      name user,
      string first_name,
      string last_name,
      string street,
      string city,
      string state
    ) {
      require_auth( user );
      address_index addresses(_code, _code.value);
      auto iterator = addresses.find(user.value);
      if ( iterator == addresses.end() ) {
        addresses.emplace(user, [&]( auto& row ) {
         row.key = user;
         row.first_name = first_name;
         row.last_name = last_name;
         row.street = street;
         row.city = city;
         row.state = state;
        });
      } else {
        string changes;
        addresses.modify(iterator, user, [&]( auto& row ) {
          row.key = user;
          row.first_name = first_name;
          row.last_name = last_name;
          row.street = street;
          row.city = city;
          row.state = state;
        });
      }
    }

    [[eosio::action]]
    void erase(name user) {
      require_auth(user);
      address_index addresses(_self, _code.value);
      auto iterator = addresses.find(user.value);
      eosio_assert(iterator != addresses.end(), "Record does not exist");
      addresses.erase(iterator);
    }

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
    };

    typedef eosio::multi_index<"people"_n, person> address_index;
};

EOSIO_DISPATCH( addressbook, (upsert)(erase))
