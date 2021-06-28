import React from 'react';

const Card = ({ text, image, id }) => (
  <div className="card" id={id}>
    <>
      <figure className="image-container">
        <img className="image" src={image} alt="dab" />
      </figure>
      <p className="text">{text}</p>
    </>
  </div>
);

export default Card;
