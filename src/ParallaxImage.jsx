import React from 'react';

const ParallaxImage = ({
  caption, image, id, text,
}) => (
  <div className="parallax-image">
    <div className="background-image" id={id} style={{ backgroundImage: `url("${image}")` }}>
      {caption ? <div className="caption">{caption}</div> : null}
    </div>
    {text ? (
      <div className="paragraph-text">
        <p>{text}</p>
      </div>
    ) : null}
  </div>
);

export default ParallaxImage;
