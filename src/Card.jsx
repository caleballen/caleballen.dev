import React, { useEffect, useRef, useState } from 'react';

const Card = ({ children }) => {
  const [isVisible, setVisible] = useState(false);
  const domRef = useRef();

  useEffect(() => {
    const observer = new IntersectionObserver((entries) => {
      entries.forEach((entry) => setVisible(entry.isIntersecting));
    });
    observer.observe(domRef.current);
    return () => observer.unobserve(domRef.current);
  }, []);

  return (
    <div className={`card fade-in ${isVisible ? 'is-visible' : ''}`} ref={domRef}>{children}</div>
  );
};

export default Card;
