#include <eosiolib/eosio.hpp>
#include <eosiolib/print.hpp>
#include <eosiolib/asset.hpp>

using namespace eosio;

class [[eosio::contract]] restricted_content : public eosio::contract {
  public:
    using contract::contract;

    [[eosio::action]]
    void send_payment() {

    }
}

EOSIO_DISPATCH( restricted_content, (send_payment))
