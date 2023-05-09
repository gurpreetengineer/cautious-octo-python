import React, { useState } from 'react';
import { CardElement, useStripe, useElements } from '@stripe/react-stripe-js';

/**
 * To install use command
 * npm i @stripe/react-stripe-js
 */

const PaymentForm = () => {
  const [loading, setLoading] = useState(false);
  const stripe = useStripe();
  const elements = useElements();

  const handleSubmit = async (event) => {
    event.preventDefault();
    setLoading(true);

    const { error, paymentMethod } = await stripe.createPaymentMethod({
      type: 'card',
      card: elements.getElement(CardElement),
    });

    if (!error) {
      // Send paymentMethod.id to server for payment processing
      // Show success message to user
    } else {
      // Show error message to user
    }

    setLoading(false);
  };

  return (
    <form onSubmit={handleSubmit}>
      <label>
        Card details
        <CardElement />
      </label>

      <button type="submit" disabled={!stripe || loading}>
        {loading ? 'Processing...' : 'Pay'}
      </button>
    </form>
  );
};

export default PaymentForm;

// In this example, we import the necessary Stripe components from the @stripe/react-stripe-js library. We use the useState hook to manage the loading state of the payment form, and the useStripe and useElements hooks to access the Stripe instance and Stripe Elements respectively.

// When the user submits the form, the handleSubmit function is called. This function creates a payment method using the Stripe API, passing in the card element from the form. If there are no errors, it sends the paymentMethod.id to the server for payment processing and shows a success message to the user. If there is an error, it shows an error message to the user.

// Finally, we render the payment form, including a CardElement for the user to enter their card details and a button that is disabled while the form is loading or if there is no Stripe instance available.

// Note that this is just a basic example and you will need to customize the form and add additional functionality based on your specific payment gateway requirements.
