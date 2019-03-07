# Example code, doesn't work

import eosiolib/eosio as eosio

class hello(eosio.contract):
    # eosio.action
    def hi(user):
        print("Hello, " + user)
