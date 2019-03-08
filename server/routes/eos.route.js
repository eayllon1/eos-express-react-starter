const express = require('express');
const router = express.Router();
const { Api, JsonRpc, RpcError } = require('eosjs');
const JsSignatureProvider = require('eosjs/dist/eosjs-jssig').default;
const { TextEncoder, TextDecoder } = require('util');
const fetch = require('node-fetch');
const config = require('../config');

const defaultPrivateKey = config.WALLET_PRIVATE_KEY; // bob
const signatureProvider = new JsSignatureProvider([defaultPrivateKey]);
const rpc = new JsonRpc('http://localhost:8888', { fetch });
const api = new Api({ rpc, signatureProvider, textDecoder: new TextDecoder(), textEncoder: new TextEncoder() });


/* GET users listing. */
router.get('/', async function(req, res, next) {
  const resp = await rpc.get_table_rows({
      json: true,              // Get the response as json
      code: 'addressbook',     // Contract that we target
      scope: 'addressbook',    // Account that owns the data
      table: 'people',         // Table name
      limit: 10,               // maximum number of rows that we want to get
  });

  console.log(resp);

  res.json(resp);
});

router.post('/', async function(req, res, next) {
  const result = await api.transact({
    actions: [{
      account: 'addressbook',
      name: 'upsert',
      authorization: [{
        actor: req.body.account,
        permission: 'active',
      }],
      data: {
        user: req.body.account,
        first_name: req.body.first_name,
        last_name: req.body.last_name,
        street: req.body.street,
        city: req.body.city,
        state: req.body.state,
      },
    }]
  }, {
    blocksBehind: 3,
    expireSeconds: 30,
  });

  console.log(result)

  res.json(result);

});


module.exports = router;
